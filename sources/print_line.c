#include "scene.h"
#include "discrete_ratio_tracking.h"

static int					characterize_slope(
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
	return (is_x_slope ? X : Y);
}

#define DIM_OFST ARGBS
static int					get_truint_decomposition(
	t_s_lp const *const l,
	t_ruint const dt,
	int const along,
	t_ruint **ret)
{
	t_delta_n_init	tdni[ARGBS + 1];
	int				r;

	targb_par_to_tdni(l->argb[0], l->argb[1], dec);
	tdni[DIM_OFST][INIT] = l->ends[0][along];
	tdni[DIM_OFST][DT] = l->ends[1][along] - tdni[DIM_OFST][INIT];
	r = track_ratios(dt, tdni, ARGBS + 1, ret);
	return (r);
}

int							print_line_like_really_really(
	t_s_lp *const l,
	int along,
	t_ruint *dec,
	t_s_sv *v)
{
	int const		sign = l->ends[1][along] > l->ends[0][along] ? 1 : -1;
	t_argb *const	pxl = v->pxl;
	double			*prec;
	t_vuint			dt;
	t_vuint			strt;

	if (get_precendences(l, along, &prec) != SUCCESS)
		return (SYS_ERR);
	strt = l->ends[0][along];
	dt = l->ends[1][along] - strt + 1;
	if (along == X)
		while (dt--)
		{
			pxl[j][
		}
}

/*
** - 'along' : slope along this axis.
**	If along == X, delta-x is greater than delta-y.
*/
int							print_line(
	t_s_sv *v,
	t_tag t)
{
	t_s_lp *const	l = &(v->e[e_slna].ar[t >> TPS])[t & TPM];
	t_ruint			dt;
	t_ruint			*dec;
	int				along;
	int				r;

	along = characterize_slope(l->ends, &dt);
	if ((r = get_truint_decomposition(l, dt, along, &dec)) != SUCCESS)
		return (r);
	print_line_like_really(l, along, dec, v);
	free(dec);
	return (SUCCESS);
}
