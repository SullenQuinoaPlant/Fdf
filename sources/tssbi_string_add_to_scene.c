/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tssbi_string_add_to_scene.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 20:54:46 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/22 18:37:51 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "parse.h"
#include "scene.h"

static int				no_scene_builder(
	void *a,
	t_s_s *b)
{
	(void)a;
	(void)b;
	return (SUCCESS);
}

static int				use_input(
	t_s_sbi *input,
	t_s_s *scene)
{
	t_scene_builder	f[e_sit_sz] = {
		no_scene_builder,
		cdgfxyrz_builder
	};

	return (f[input->type](input->input, scene));
}

stotic void				check_minmax(
	t_xyz	sbi_minmax[MIN_MAX_SZ],
	t_xyz	s_minmax[MIN_MAX_SZ])
{
	int		i;

	i = -1;
	while (++i < DIMS)
	{
		if (s_minmax[MIN][i] > sbi_minmax[MIN][i])
			s_minmax[MIN][i] = sbi_minmax[MIN][i];
		if (s_minmax[MAX][i] < sbi_minmax[MAX][i])
			s_minmax[MAX][i] = sbi_minmax[MAX][i];
	}
}

int						add_tssbis_to_scene(
	t_s_sbi **input_str,
	t_s_s *scene)
{
	t_s_sbi	*p;
	int		r;

	r = SUCCESS;
	while ((p = *input_str))
	{
		if ((r = use_input(p, scene) != SUCCESS))
			break;
		check_minmax(p->minmax, scene->minmax);
		input_str++;
	}
	return (r);
}
