/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tssbi_string_add_to_scene.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 20:54:46 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/24 21:29:37 by nmauvari         ###   ########.fr       */
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

static int				check_minmax(
	t_xyz	sbi_minmax[MIN_MAX_SZ],
	t_xyz	s_minmax[MIN_MAX_SZ])
{
	int		i;
	int		has_changed;

	has_changed = 0;
	i = -1;
	while (++i < DIMS)
	{
		if (s_minmax[MIN][i] > sbi_minmax[MIN][i])
		{
			s_minmax[MIN][i] = sbi_minmax[MIN][i];
			has_changed = 1;
		}
		if (s_minmax[MAX][i] < sbi_minmax[MAX][i])
		{
			s_minmax[MAX][i] = sbi_minmax[MAX][i];
			has_changed = 1;
		}
	}
	return (has_changed);
}

int						add_tssbis_to_scene(
	t_s_sbi **input_str,
	t_s_s *s)
{
	t_s_sbi	*p;
	int		mm_chg;
	int		r;

	r = SUCCESS;
	mm_chg = 0;
	while ((p = *input_str))
	{
		if ((r = use_input(p, s) != SUCCESS))
			break;
		mm_chg = check_minmax(p->minmax, s->minmax);
		input_str++;
	}
	if (mm_chg)
		scene_set_extr(s);
	return (r);
}
