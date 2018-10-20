/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 16:13:23 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/20 16:33:06 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "functions.h"
#include "scene.h"

void				print_scene_points(
	t_s_s *s)
{
	t_s_se	*pts;
	t_s_p	*p;
	size_t	i;
	size_t	j;

	pts = &s->e[e_p];
	i = -1;
	while (++i < pts->ar_sz)
	{
		p = pts->ar[i];
		j = -1;
		while (++j < TAS)
		{
			printf("xyz: %f %f %f\t", p->xyz[X], p->xyz[Y], p->xyz[Z]);
			p++;
		}
	}
}

int				main(
	int ac,
	char **av)
{
	t_s_sbi	*input[2];
	t_s_s	*s;
	int		r;

	input[1] = 0;
	s = 0;
	r = SUCCESS;
	if (ac != 2 ||
		((r = get_cdgfxyrz_sbi(av[1], input)) != SUCCESS && r == BAD_INFILE))
		r = usage();
	else if (r == SUCCESS &&
		(r = make_scene(input, &s)) == SUCCESS &&
		!(r = add_isometric_v((t_vpos){478, 2550}, (t_zntr){0.01, 0, 0, 0}, s)))
	{
		print_scene_points(s);
		printf("\n");
		tssv_print_ascii(s->v);
	}
	scene_teardown(&s);	
	if (r != SUCCESS)
		report_error(r);
	return (r);
}
