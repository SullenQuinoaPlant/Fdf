/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tssv_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 21:11:37 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/14 06:37:30 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

static int					tssv_add_tar(
	void *p_seg,
	t_ring p_tssv)
{
	t_s_sv *const	v = (t_s_sv*)p_tssv;
	t_s_s *const	s = v->s;
	t_e_seg const	g = *(t_e_seg*)p_seg;
	t_s_ta *const	ta = &v->e[g];
	int		r;

	if ((r = alloc_tar(s, ta->e_sz, &ta->ar_sz, &ta->ar)) == SUCCESS)
		r = RING_SUCCESS;
	else
		r = RING_SYS_ERR;
	return (r);
}

int							tssvs_tar_allocs(
	t_e_seg grp,
	t_s_s *s)
{
	int		r;

	r = ring_apply(&s->v, tssv_add_tar, &grp);
	r = r == RING_SUCCESS ? SUCCESS : SYS_ERR;
	return (r);
}

void						tssv_apply_proj(
	t_s_sv *v,
	t_proj proj,
	t_s_se *s_grp,
	t_s_ta *v_grp)
{
	t_u_spsv const *const *const	pnv = v->e[e_spnv].ar;
	void							*p_ve;
	void							*p_se;
	void							*lim_ve;
	size_t							i;

	i = -1;
	while (++i < v_grp->ar_sz)
	{
		p_ve = v_grp->ar[i]
		p_se = s_grp->ar[i]
		lim_ve = p_ve + TAS * v_grp->e_sz;
		while (p_ve < lim_ve)
		{
			(*proj)(v, p_se, pnv, p_ve);
			p_se += s_grp->e_sz;
			p_ve += v_grp->e_sz;
		}
	}
}

void						tssv_seg_apply_proj(
	void *p_seg,
	t_ring p_tssv)
{
	t_s_sv *const	v = (t_s_sv*)p_tssv;
	t_s_s *const	s = v->s;
	t_e_seg const	g = *(t_e_seg*)p_seg;
	t_s_ta *const	ta = &v->e[g];

	tssv_grp_apply_proj(v, v->prj[g], &s->e[g], &v->e[g]);
}

int							tssvs_seg_apply_proj(
	t_e_seg grp,
	t_s_s *s)
{
	int		r;

	r = ring_apply(&s->v, tssv_seg_apply_proj, &grp);
	r = r == RING_SUCCESS ? SUCCESS : SYS_ERR;
	return (r);
}
