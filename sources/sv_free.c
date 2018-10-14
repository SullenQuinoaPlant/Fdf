/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sv_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 05:35:37 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/14 08:34:57 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

static void				free_view_members(
	void *view,
	size_t ttl_sz)
{
	t_s_sv *const	v = (t_s_sv*)view;
	t_e_vpg			i;

	if (!view)
		return ;
	onelessview(v->ct);
	i = -1;
	while (++i < e_seg_sz)
		free_tar(v->e[i].ar, v->e[i].ar_sz, v->e[i].e_sz, v->s);
	ft_cleanfree(v->view, sizeof(t_s_pxl) * v->h * v->w);
	ft_cleanfree(view, ttl_sz);
}

void					free_view(
	t_s_sv *ring_bit)
{
	ring_shrink(sizeof(t_s_sv), free_view_members, (void**)&ring_bit);
}

void					free_views(
	t_s_sv *ring)
{
	ring_free(sizeof(t_s_sv), free_view_members, (void**)&ring);
}
