/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_view.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 06:16:07 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/18 18:15:13 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "scene.h"

static void				set_prj(
	t_s_sv *v)
{
	t_proj const	ar[e_seg_sz] = {
		point_projection,
		isometric_dot_proj,
		isometric_line_proj,
		0,
		0,
		obj_projection};

	ft_memcpy(v->prj, ar, sizeof(ar));
}

int						add_isometric_v(
	t_vpos hw,
	t_zntr cam_pos,
	t_s_s *s)
{
	t_s_sv		*new_v;
	int			i;
	int			r;

	if ((r = add_view(s, &new_v)) == SUCCESS &&
		(new_v->ct = add_isometric_camera(cam_pos, s)) &&
		(r = tssv_add_pxl_ars(hw[V_H], hw[V_W], new_v)) == SUCCESS)
	{
		set_prj(new_v);
		i = -1;
		while (++i < e_seg_sz)
			tssv_seg_apply_proj(&i, new_v);
		return (SUCCESS);
	}
	if (r == SUCCESS)
		free_view(s->v);
	return (SYS_ERR);
}
