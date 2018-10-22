/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_view.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 06:16:07 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/22 19:21:13 by nmauvari         ###   ########.fr       */
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
	t_e_seg			i;

	i = e_p;
	while (i < e_seg_sz)
	{
		v->e[i].prj = ar[i];
		i++;
	}
}

static void				set_prt(
	t_s_sv *v)
{
	t_printer const	ar[e_seg_sz] = {
		0,
		print_dot,
		print_isometric_line,
		0,
		0,
		print_object};
	t_e_seg			i;

	i = e_p;
	while (i < e_seg_sz)
	{
		v->e[i].prt = ar[i];
		i++;
	}
}

int						add_isometric_v(
	t_vpos hw,
	t_zntr cam_pos,
	t_s_sv **ret_v,
	t_s_s *s)
{
	t_s_sv		*new_v;
	int			r;

	if ((r = add_view(s, hw, &new_v)) == SUCCESS &&
		(new_v->ct = add_isometric_camera(cam_pos, s)))
	{
		new_v->vt = e_iso;
		set_prj(new_v);
		tssv_apply_projs(new_v);
	}
	else if (r == SUCCESS)
	{
		r = SYS_ERR;
		free_view(&s->v);
	}
	if (ret_v)
		*ret_v = new_v;
	return (r);
}

int						add_default_iso_v(
	t_s_sv **ret_v,
	t_s_s *s)
{
	return (add_isometric_v(s->v_hw_def, 0, ret_v, s));
}
