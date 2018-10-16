#include "scene.h"
#include "discrete_ratio_tracking.h"

static int					set_precedences(
	double ends[2],
	t_ruint dt,
	double **ret)
{
	double const	inc = (ends[1] - ends[0]) / (double)dt;
	t_vuint			len;
	double			d;
	double			*p;

	*ret = 0;
	len = dt + 1;
	if (!(p = malloc((len * double))))
		return (SYS_ERR);
	d = ends[1];
	while (len--)
	{
		p[len] = d
		d -= inc;
	}
	return (SUCCESS);
}

static void					print_line_like_really(
	t_s_sv *v,
	t_ruint *decomposed,
	double *prec,
	t_ruint dt)
{
	t_rgba (*cnst	canvas)[v->w] = v->pxl;
	t_ruint (*const	dec)[ARGBS + V_DIMS] = decomposed;
	t_vuint		h;
	t_vuint		w;

	dt++;
	while (dt--)
	{
		h = dec[dt][DIM_OFST + V_H];
		w = dec[dt][DIM_OFST + V_W];
		if (prec[dt] < v->pxl_prec[h][w])
			canvas[h][w] = recompose_truint_targb(
	}
}

int							print_line(
	t_s_sv *v,
	t_tag t)
{
	t_s_lp *const	l = &(v->e[e_slna].ar[t >> TPS])[t & TPM];
	t_ruint			*dec;
	t_ruint			dt;
	double			*prec;
	int				r;

	dec = 0;
	prec = 0;
	if ((r = track_pixel_line(l, &dt, 0, &dec)) == SUCCESS &&
		(r = set_precedences(l->prec, dt, &prec)) == SUCCESS)
		print_line_like_really(v, dec, prec, dt);
	if (prec)
		free(prec);
	if (dec)
		free(dec);
}
