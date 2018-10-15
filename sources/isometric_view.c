/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_view.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 06:16:07 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/15 06:17:08 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

static void				set_prj(
	t_s_sv *v)
{
	t_proj const	ar[e_seg_sz] = {
		pnv_projection,
		isometric_dot_proj,
		isometric_loa_proj,
		0,
		obj_proj};

	ft_memcpy(v->prj, ar, sizeof(ar));
}

int						add_isometric_v(
	t_s_s *s
	t_vuint h,
	t_vuint w)
{
	t_s_sv		*new;
	t_s_pctr	*ct;
	int			i;
	int			r;

	if ((r = add_view(s, &new)) == SUCCESS &&
		(new->ct = add_isometric_camera) &&
		(r = tssv_add_pixel_ars(h, w, v)) == SUCCESS)
	{
		set_prj(new);
		i = -1;
		while (++i < e_seg_sz)
			tssv_seg_apply_proj(*i, v);
		return (SUCCESS);
	}
	if (r == SUCCESS)
	{
		if (new->ct)
			onelessview(new->ct);
		ring_shrink(sizeof(t_s_v), free_view_members, (void**)&new);
	}
	return (SYS_ERR);
}
