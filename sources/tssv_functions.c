/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tssv_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 21:11:37 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/11 21:14:16 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_e_vpg						map_seg_to_vpg(
	t_e_seg sg)
{
	if (sg == e_slna)
		return (e_vpg);
	if (sg == e_sd)
		return (e_vdg);
	if (sg == e_slna)
		return (e_vlnag);
	if (sg == e_sf)
		return (e_vfg);
	if (sg == e_so)
		return (e_vog);
	return (e_vpg_null);
}

static int					tssv_add_tar(
	void *p_vpg,
	t_ring p_tssv)
{
	t_s_sv *const	v = (t_s_sv*)p_tssv;
	t_s_s *const	s = v->s;
	t_e_vpg const	g = *(t_e_vpg*)p_vpg;
	t_s_ta *const	ta = &v->e[g];
	int		r;

	if ((r = alloc_tar(s, ta->e_sz, &ta->ar_sz, &ta->ar)) == SUCCESS)
		r = RING_SUCCESS;
	else
		r = RING_SYS_ERR;
	return (r);
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
