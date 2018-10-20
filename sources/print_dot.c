#include "scene.h"

int							print_dot(
	t_s_sv *v,
	t_tag t)
{
	t_s_dp *const	d = &((t_s_dp*)v->e[e_d].ar[t >> TPS])[t & TPM];
	t_argb (*const	pxl)[v->w] = (t_argb(*)[v->w])v->pxl;
	double (*const	prec)[v->w] = (double(*)[v->w])v->pxl_prec;
	t_vuint const	w = d->here[V_W];
	t_vuint const	h = d->here[V_H];

	if (prec[h][w] < d->prec)
		return (SUCCESS);
	prec[h][w] = d->prec;
	pxl[h][w] = d->argb;
	return (SUCCESS);
}
