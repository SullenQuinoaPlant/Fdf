/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tssv_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 05:35:37 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/23 23:28:58 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "scene.h"

static void				free_pxl_ars(
	t_s_sv *v)
{
	size_t const	sz = v->h * v->w * sizeof(double);

	if (v->pxl_prec)
	{
		free(v->pxl_prec);
		v->s->pxl_allocs += sz;
	}
}

static void				release_mlx_ptrs(
	t_s_sv *v)
{
	void *const	mlx = v->s->mlx;

	if (v->mlx_img)
		mlx_destroy_image(>mlx, v->mlx_img);
	if (v->mlx_wdw)
		mlx_destroy_window(mlx, v->mlx_wdw);
}

static void				free_view_members(
	void *view,
	size_t ttl_sz)
{
	t_s_sv *const	v = (t_s_sv*)view;
	t_e_seg			i;

	if (!view)
		return ;
	tspctr_onelessview(v->ct);
	i = -1;
	while (++i < e_seg_sz)
		free_tar(v->e[i].ar, v->e[i].ar_sz, v->e[i].e_sz, v->s);
	free_pxl_ars(v);
	release_mlx_ptrs(v);
	ft_cleanfree(view, ttl_sz);
}

void					free_view(
	t_s_sv **ring_bit)
{
	t_s_s *const	s 
	while (
	ring_shrink(sizeof(t_s_sv), free_view_members, (void**)ring_bit);
}

void					free_views(
	t_s_sv **ring)
{
	ring_free(sizeof(t_s_sv), free_view_members, (void**)ring);
}
