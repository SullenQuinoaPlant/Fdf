#include "scene.h"

void						print_dot(
	t_s_sv *v,
	t_tag t)
{
	t_s_dp *const	d = &(v->e[e_sd].ar[t >> TPS])[t & TPM];
	t_argb (*const	pxl)[v->w] = v->pxl;
	double (*const	prec)[v->w] = v->pxl_prec;
	t_vuint const	w = d->here[V_W];
	t_vuint const	h = d->here[V_H];

	if (prec[h][w] < d->prec)
		return ;
	prec[h][w] = d->prec;
	pxl[h][w] = d->argb;
}
