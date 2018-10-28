/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_view.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 06:16:07 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/28 03:28:58 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "mlx.h"
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

static void				set_hooks(
	t_s_sv *v)
{
	mlx_key_hook(v->mlx_wdw, (int(*)())isometric_keyhooks, v);
}

int						add_isometric_v(
	t_vpos hw,
	t_zntr cam_pos,
	t_s_sv **ret_v,
	t_s_s *s)
{
	t_s_sv		*new_v;
	int			r;

	new_v = 0;
	if ((r = add_view(s, hw, &new_v)) == SUCCESS &&
		(new_v->ct = add_isometric_camera(cam_pos, s)))
	{
		new_v->vt = e_iso;
		set_prj(new_v);
		set_prt(new_v);
		set_hooks(new_v);
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
