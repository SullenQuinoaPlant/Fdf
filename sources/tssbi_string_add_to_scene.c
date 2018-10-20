/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tssbi_string_add_to_scene.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 20:54:46 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/20 19:13:52 by nmauvari         ###   ########.fr       */
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

int						add_tssbis_to_scene(
	t_s_sbi **input_str,
	t_s_s *scene)
{
	int		r;

	while (*input_str)
		if ((r = use_input(*input_str++, scene) != SUCCESS))
			break;
	return (r);
}
