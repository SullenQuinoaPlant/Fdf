/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_view.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 06:16:07 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/15 05:09:45 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

static int				set_prj(
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
	int		r;

	if ((r = add_view(s, &new)) == SUCCESS &&
		(new->ct = add_isometric_camera) &&
		(new->view = malloc(h * w * sizeof(pxl))))
	{
		set_prj(new);
		new->h = h;
		new->v = w;
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
