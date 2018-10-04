#include "scene.h"

t_e_vpg						map_seg_to_vpg(
	t_e_seg sg)
{
	if (sg == e_slna)
		return (e_vpg);
	if (sg == e_sd)
		return (e_vdg);
	if (sg == e_slna)
		return (e_vlnag)
	if (sg == e_sf)
		return (e_vfg);
	if (sg == e_so)
		return (e_vog);
	return (e_vp_null);
}

static int					tssv_add_tar(
	void *p_vpg,
	t_ring p_tssv)
{
	t_s_sv *const	v = (t_s_sv*)p_tssv;
	t_s_s *const	s = sv->s;
	t_e_vpg const	g = *(t_e_vpg*)p_vpg;
	t_s_ta			*ta;
	int		r;

	ta = &v->ve[g];
	if ((r = alloc_tar(s, ta->e_sz, &ta->ar_sz, &ta->ar)) == SUCCESS)
		r = RING_SUCCESS;
	else
		r = RING_SYS_ERR;
	return (r)
}
	
int							tssv_tar_allocs(
	t_e_vpg grp,
	t_s_s *s)
{
	int		r;

	r = ring_apply(&s->v, tssv_add_tar, &grp);
	r = r == RING_SUCCESS ? SUCCESS : SYS_ERR;
	return (r);
}
