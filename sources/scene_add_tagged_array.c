/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_add_tagged_array.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 21:08:08 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/20 20:13:30 by nmauvari         ###   ########.fr       */
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

	if ((r = tssvs_add_tar(g, s)) == SUCCESS &&
		(r = inc_tar_alloc(s, se->e_sz, &se->ar_sz, &se->ar)) == SUCCESS)
		r = reg_teseg_freetags(((t_tag)se->ar_sz - 1) << TPS, TPM, s, g);
	return (r);
}
