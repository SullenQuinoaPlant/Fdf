#include "scene.h"
#include "discrete_ratio_tracking.h"

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

static double				*set_precendences(
	t_s_sv const *const v,
	t_s_lp const *const l,
	t_ruint const (*const dec)[ARGBS + 1],
	int const along)
{
	double (*const	pxl_prec)[v->w] = v->pxl_prec;
	double			*p;
	int				r;

	if ((p = malloc(
}

int							print_line_like_really(
	t_s_lp const *const l,
	int const along,
	t_ruint const (*const dec)[ARGBS + 1],
	t_s_sv *const v)
{
	int const		sign = l->ends[1][along] > l->ends[0][along] ? 1 : -1;
	t_argb (*const	pxl)[v->w] = v->pxl;
	double			*prec;
	t_vuint			dt;
	t_vuint			cursor;

	if (set_precendences(v, l, along, &prec) != SUCCESS) //NOT DONE
		return (SYS_ERR);
	cursor = l->ends[0][along] - 1;
	dt = l->ends[1][along] - strt + 1;
	if (along == V_W)
		while (dt--)
		{
			cursor += sign;
			if (prec[dt] < v->pxl_prec[(cursor + dt)  + dec[dt][DIM_OFST] * v->w])
			if (prec[dt] != 0) //CHANGE THIS TO SOMETHING SENSIBLE
				continue ;
			pxl[cursor + dt][dec[dt][DIM_OFST]] = recomp_targb(dec[dt]);
		}
}

/*
** - 'along' : slope along this axis.
**	If along == V_W, delta-x is greater than delta-y.
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
