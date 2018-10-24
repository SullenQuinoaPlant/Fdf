/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tssv_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 05:35:37 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/24 21:52:23 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "scene.h"

static void				ring_free_view(
	void *view,
	size_t ttl_sz)
{
	t_s_sv *const	v = (t_s_sv*)view;

	free_view_members(v);
	ft_cleanfree(view, ttl_sz);
}

void					free_view(
	t_s_sv **ring_bit)
{
	ring_shrink(sizeof(t_s_sv), ring_free_view, (void**)ring_bit);
}

void					free_views(
	t_s_sv **ring)
{
	ring_free(sizeof(t_s_sv), ring_free_view, (void**)ring);
}
