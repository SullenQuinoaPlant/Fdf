/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_add_tagged_array.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 21:08:08 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/11 21:08:10 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "scene.h"

int							add_star(
	t_e_seg g,
	t_s_s *s)
{
	t_s_se *const	se = &s->e[g];
	int				r;

	if ((r = tssv_tar_allocs(map_seg_to_vpg(g), s)) == SUCCESS &&
		(r = alloc_tar(s, se->e_sz, &se->ar_sz, &se->ar)) == SUCCESS &&
		(reg_tesegfreetags(((t_tag)se->ar_sz) << TPS, TPM, s, g)) == SUCCESS)
		return (SUCCESS);
	return (r);
}
