#include "scene.h"
#include "discrete_ratio_tracking.h"

static int					is_x_slope(
	t_vpos ends[2],
	t_ruint *dt)
{
	t_vuint	dt_x;
	t_vuint	dt_y;
	char	is_x_slope;

	if (ends[1][X] > ends[0][X])
		dt_x = ends[1][X] - ends[0][X];
	else
		dt_x = ends[0][X] - ends[1][X];
	if (ends[1][Y] > ends[0][Y])
		dt_x = ends[1][Y] - ends[0][Y];
	else
		dt_x = ends[0][Y] - ends[1][Y];
	if ((is_x_slope = dt_x >= dt_y ? 1 : 0))
		*dt = dt_x;
	else
		*dt = dt_y;
	return (is_x_slope);
}

#define DIM_OFST ARGBS
static int					get_truint_decomposition(
	t_s_lp const *const l,
	t_ruint const dt,
	char const is_x_slope,
	t_ruint **ret)
{
	t_delta_n_init	dec[ARGBS + 1];
	int const		i = is_x_slope ? X : Y;
	int				r;

	targb_to_truint_dec(l->argb[0], l->argb[1], dec);
	dec[DIM_OFST][INIT] = l->ends[0][i];
	dec[DIM_OFST][DT] = l->ends[1][i] - l->ends[0][i];
	r = track_ratios(dt, dec, ARGBS + 1, ret);
	return (r);
}

int							print_line_like_really(
	t_s_lp *const l,
	char x,
	t_ruint *dec,
	t_s_sv *v)
{
	int const	sign = l->ends[1][x ? X : Y] > l->ens[0][x ? X : Y] ? 1 : -1;
	t_vuint		strt;
	t_argb		col;

	strt = l->ends[0][x ? X : Y];
	while (1)
	{
		
	}
}

int							print_line(
	t_s_sv *v,
	t_tag t)
{
	t_s_lp *const	l = &(v->e[e_slna].ar[t >> TPS])[t & TPM];
	t_ruint			dt;
	t_ruint			*dec;
	char			is_x_slope;
	int				r;

	is_x_slope = is_x_slope(l->ends)
	if ((r = get_truint_decomposition(l, dt, is_x_slope, &dec)) != SUCCESS)
		return (r);
	print_line_like_really(l, is_x_slope, dec, v);
	free(dec);
	return (SUCCESS);
}
