#include "scene.h"

/*
**This ought to be a copy, modulo the types,
**	of free_tar()
**Which is why we're getting rid of it.
static void				free_vpnvs(
	size_t ar_sz,
	t_u_spsv **vpnv)
{
	size_t const		sz = TAS * sizeof(t_u_spsv);
	t_u_spsv **const	lim = vpnv + ar_sz;
	t_u_spsv			**p;

	if (!*(p = vpnv))
		return ;
	while (p < lim)
		ft_cleanfree(*p++, sz);
	ft_cleanfree(vpnv, ar_sz * sizeof(t_u_spsv*));
}
*/

static void				free_view_members(
	void *view,
	size_t ttl_sz)
{
	t_s_sv *const	v = (t_s_sv*)view;
	t_e_vpg			i;

	if (!view)
		return ;
	onelessview(v->ct);
	i = -1;
	while (++i < e_seg_sz)
		free_tar(v->e[i].ar, v->e[i].ar_sz, v->e[i].e_sz);
	ft_cleanfree(v->view, sizeof(t_s_pxl) * v->h * v->w);
	ft_cleanfree(view, ttl_sz);
}

void					free_view(
	t_s_sv *ring_bit)
{
	ring_shrink(sizeof(t_s_sv), free_view_members, (void**)&ring_bit);
}

void					free_views(
	t_s_sv *ring)
{
	ring_free(sizeof(t_s_sv), free_view_members, (void**)&ring);
}
