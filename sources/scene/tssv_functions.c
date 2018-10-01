#include "scene.h"

t_e_vp						map_seg_to_veg(
	t_e_seg sg)
{
	if (sg == e_sd)
		return (e_vd);
	if (sg == e_slna)
		return (e_vlna)
	if (sg == e_sf)
		return (e_vf);
	if (sg == e_so)
		return (e_vo);
	return (e_vp_null);
}

static t_s_ta				*get_tsta(
	t_s_sv *sv,
	t_e_seg sg)
{
	t_e_vp	vg;
	t_s_ta	*ret;

	ret = 0;
	if ((vg = map_seg_to_vp(sg)) != e_vp_null)
		ret = &sv->es[vg];
	return (ret);
}

static int					tssv_add_tar(
	void *p_seg,
	t_ring p_tssv)
{
	t_s_sv *const	sv = (t_s_sv*)p_tssv;
	t_s_s *const	s = sv->scene;
	t_e_seg const	sg = *(t_e_seg*)p_seg;
	t_s_ta			*ta;
	int		r;

	ta = get_tsta(sv, sg);
	if ((r = alloc_tar(s, ta->e_sz, &ta->ar_sz, &ta->ar)) == SUCCESS)
		r = RING_SUCCESS;
	else
		r = RING_SYS_ERR;
	return (r)
}
	
int							tspcs_tar_alloc(
	t_s_s *s)
{
	int		r;

	r = ring_apply(&s->canonical, tssv_add_tar, s);
	r = r == RING_SUCCESS ? SUCCESS : SYS_ERR;
	return (r);
}
