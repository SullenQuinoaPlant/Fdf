#include "scene.h"

static void					tssv_grp_apply_proj(
	t_s_sv *v,
	t_s_se *s_grp,
	t_s_ve *v_grp)
{
	t_s_p const *const *const	pts = (t_s_p**)v->e[e_p].ar;
	void						*p_ve;
	void						*p_se;
	void						*lim_ve;
	size_t						i;

	i = -1;
	while (++i < v_grp->ar_sz)
	{
		p_ve = v_grp->ar[i]
		p_se = s_grp->ar[i]
		lim_ve = p_ve + TAS * v_grp->e_sz;
		while (p_ve < lim_ve)
		{
			(*v_grp->prj)(v, p_se, pts, p_ve);
			p_se += s_grp->e_sz;
			p_ve += v_grp->e_sz;
		}
	}
	v_grp->tick = v->e[e_p].tick;
}

void						tssv_apply_projs(
	t_s_sv *v)
{
	t_e_seg		i;

	i = e_p;
	while (i < e_seg_sz)
	{
		tssv_grp_apply_proj(v, &v->s->e[i], &v->e[i]);
		i++;
	}
}

void						tssv_ring_seg_apply_proj(
	void *p_seg,
	t_ring p_tssv)
{
	t_s_sv *const	v = (t_s_sv*)p_tssv;
	t_s_s *const	s = v->s;
	t_e_seg const	g = *(t_e_seg*)p_seg;
	t_s_ta *const	ta = &v->e[g];

	tssv_grp_apply_proj(v, &s->e[g], &v->e[g]);
}

int							tssvs_seg_apply_proj(
	t_e_seg grp,
	t_s_s *s)
{
	int		r;

	r = ring_apply(&s->v, tssv_ring_seg_apply_proj, &grp);
	r = r == RING_SUCCESS ? SUCCESS : SYS_ERR;
	return (r);
}
