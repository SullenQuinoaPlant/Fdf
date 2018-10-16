#include "scene.h"
#include "discrete_ratio_tracking.h"

void							recompose_truint_targb(
	t_ruint *dec,
	t_argb *ret)
{
	t_argb	col;
	int		i;

	i = -1;
	col = 0;
	while (++i < ARGBS)
	{
		col << ARGB_SHIFT;
		col |= dec[i];
	}
	*ret = col;
}

void							targb_pair_to_tdni(
	t_argb argbs[2],
	t_delta_n_init *ret)
{
	t_argb argb1
	t_argb argb2,
	int		i;
	t_ruint	c;

	argb1 = argbs[0];
	argb2 = argbs[1];
	i = -1;
	while (++i < ARGBS)
	{
		c = argb1 & ARGB_MASK;
		dec[i][INIT] = c;
		dec[i][DT] = argb2 & ARGB_MASK - c;
		argb1 >> ARGB_SHIFT;
		argb2 >> ARGB_SHIFT;
	}
}

void							tvpos_pair_to_tdni(
	t_vpos ends[2],
	t_delta_n_init *ret)
{
	t_ruint		val;

	ret[DIM_OFST + V_H][DT] = ends[1][V_H];
	ret[DIM_OFST + V_W][DT] = ends[1][V_W];
	val = ends[0][V_H];
	ret[DIM_OFST + V_H][DT] -= val;
	ret[DIM_OFST + V_H][INIT] = val;
	val = ends[0][V_W];
	ret[DIM_OFST + V_W][DT] -= val;
	ret[DIM_OFST + V_W][INIT] = val;
}

static int					characterize_slope(
	t_vpos ends[2],
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

int							track_pixel_line(
	t_s_lp const *const l,
	t_ruint *ret_dt
	int *ret_along,
	t_ruint **ret)
{
	t_delta_n_init	tdni[PXL_DEC_SZ];
	t_ruint			dt;
	int				along;
	int				r;

	targb_pair_to_tdni(l->argb, pxl_dec);
	tvpos_pair_to_tdni(l->ends, pxl_dec + DIM_OFST);
	along = characterize_slope(l->ends, &dt);
	if ((r = track_ratios(dt, tdni, PXL_DEC_SZ, ret)) == SUCCESS)
	{
		if (ret_dt)
			*ret_dt = dt;
		if (ret_slope_along)
			*ret_slope_along = along;
	}
	return (r);
}
