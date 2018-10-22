#include "functions.h"
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
	if (!(p = malloc(len * sizeof(double))))
		return (SYS_ERR);
	d = ends[1];
	while (len--)
	{
		p[len] = d;
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
	t_argb (*const	canvas)[v->w] = (t_argb(*)[v->w])v->pxl;
	double (*const	vprec)[v->w] = (double(*)[v->w])v->pxl_prec;
	t_ruint (*const	dec)[PXL_DEC_SZ] = (t_ruint(*)[PXL_DEC_SZ])decomposed;
	t_vuint			h;
	t_vuint			w;

	dt++;
	while (dt--)
	{
		h = dec[dt][V_H];
		w = dec[dt][V_W];
		if (prec[dt] < vprec[h][w])
			truint_dec_to_targb(&dec[dt][PXDAO], &canvas[h][w]);
	}
}

int							print_line(
	t_s_sv *v,
	t_tag t)
{
	t_s_lp *const	l = &((t_s_lp*)v->e[e_l].ar[t >> TPS])[t & TPM];
	t_ruint			*dec;
	t_ruint			dt;
	double			*prec;
	int				r;

	dec = 0;
	prec = 0;
	if ((r = track_pixel_line_ratios(l, &dt, 0, &dec)) == SUCCESS &&
		(r = set_precedences(l->prec, dt, &prec)) == SUCCESS)
		print_line_like_really(v, dec, prec, dt);
	if (prec)
		free(prec);
	if (dec)
		free(dec);
	return (r);
}
