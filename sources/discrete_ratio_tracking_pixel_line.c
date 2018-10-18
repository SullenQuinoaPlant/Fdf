#include "functions.h"
#include "scene.h"
#include "discrete_ratio_tracking.h"

void							targb_pair_to_tdni(
	t_argb const argbs[2],
	t_dni *ret)
{
	t_argb argb1;
	t_argb argb2;
	int		i;
	t_ruint	c;

	argb1 = argbs[0];
	argb2 = argbs[1];
	i = -1;
	while (++i < ARGBS)
	{
		c = argb1 & ARGB_MASK;
		ret[i][DNI_INI] = c;
		ret[i][DNI_DT] = (argb2 & ARGB_MASK) - c;
		argb1 >>= ARGB_SHIFT;
		argb2 >>= ARGB_SHIFT;
	}
}

void							tvpos_pair_to_tdni(
	t_vpos const ends[2],
	t_dni *ret)
{
	t_ruint		val;

	ret[PXL_DEC_DIM_OFST + V_H][DNI_DT] = ends[1][V_H];
	ret[PXL_DEC_DIM_OFST + V_W][DNI_DT] = ends[1][V_W];
	val = ends[0][V_H];
	ret[PXL_DEC_DIM_OFST + V_H][DNI_DT] -= val;
	ret[PXL_DEC_DIM_OFST + V_H][DNI_INI] = val;
	val = ends[0][V_W];
	ret[PXL_DEC_DIM_OFST + V_W][DNI_DT] -= val;
	ret[PXL_DEC_DIM_OFST + V_W][DNI_INI] = val;
}

static int					characterize_slope(
	t_vpos const ends[2],
	t_ruint *dt)
{
	t_vuint	dt_w;
	t_vuint	dt_h;
	char	is_w_slope;

	if (ends[1][V_W] > ends[0][V_W])
		dt_w = ends[1][V_W] - ends[0][V_W];
	else
		dt_w = ends[0][V_W] - ends[1][V_W];
	if (ends[1][V_H] > ends[0][V_H])
		dt_h = ends[1][V_H] - ends[0][V_H];
	else
		dt_w = ends[0][V_H] - ends[1][V_H];
	if ((is_w_slope = dt_w >= dt_h ? 1 : 0))
		*dt = dt_w;
	else
		*dt = dt_h;
	return (is_w_slope ? V_W : V_H);
}

static void					set_along(
	t_ruint dt,
	t_dni along,
	t_ruint *ar)
{
	t_ruint *const	lim = ar + dt + 1;
	t_ruint	v;

	v = along[DNI_INI];
	while (ar < lim)
		*ar++ = v++;
}

int							track_pixel_line(
	t_s_loap const *const l,
	t_ruint *ret_dt,
	int *ret_along,
	t_ruint **ret)
{
	t_dni			tdni[PXL_DEC_SZ];
	t_ruint			dt;
	int				along;
	t_ruint			*ar;
	int				r;

	targb_pair_to_tdni(l->argb, tdni);
	tvpos_pair_to_tdni(l->ends, tdni + PXL_DEC_DIM_OFST);
	along = characterize_slope(l->ends, &dt);
	if (!(ar = malloc(sizeof(t_ruint) * (dt + 1) * PXL_DEC_SZ)))
		return (SYS_ERR);
	track_ratios(dt, tdni, along, ar);
	track_ratios(dt, &tdni[along + 1], &ar[(along + 1) * (dt + 1)]);
	set_along(dt, tdni[along], ret);
	*ret = ar;
	if (ret_dt)
		*ret_dt = dt;
	if (ret_along)
		*ret_along = along;
	return (SUCCESS);
}
