#include "scene.h"

/*
**This outgh to be a copy, modulo the types,
**	of free_tar()
*/
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

static void				free_view_members(
	void *view,
	size_t ttl_sz)
{
	t_s_sv *const	v = (t_s_sv*)view;
	t_e_vpg			i;

	if (!view)
		return ;
	onelessview(v->ct);
	free_vpnvs(v->s->e[e_spnv].ar_sz, v->vpnv);
	i = -1;
	while (++i < e_vpg_sz)
		free_tar(v->ve[i].ar, v->ve[i].ar_sz, v->ve[i].e_sz);
	ft_cleanfree(*view, sizeof(t_s_pxl) * v->h * v->w)
	ft_cleanfree(view, sizeof(t_s_sv));
}

void					free_view(
	t_s_sv *ring_bit)
{
	ring_shrink(sizeof(t_s_sv), free_view_members, &ring_bit);
}

void					free_views(
	t_s_sv *ring)
{
	ring_free(sizeof(t_s_sv), free_view_members, &ring);
}
