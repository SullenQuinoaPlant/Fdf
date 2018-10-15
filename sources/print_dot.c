#include "scene.h"

void						print_dot(
	t_s_sv *v,
	t_s_dp *d)
{
	t_argb (*const	pxl)[v->w] = v->pxl;
	double (*const	prec)[v->w] = v->pxl_prec;
	t_vuint const	w = d->here[V_W];
	t_vuint const	h = d->here[V_H];

	if (prec[h][w] < d->prec)
		return ;
	prec[h][w] = d->prec;
	pxl[h][w] = d->argb;
}
