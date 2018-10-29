/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 16:13:23 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/29 19:31:11 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"
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


#include <stdio.h>

int				main(
	int ac,
	char **av)
{
	t_s_sbi	*input[2];
	t_s_s	*s;
	t_s_sv	*v;
	int		r;

	input[1] = 0;
	s = 0;
//	if (ac != 2 ||
//		((r = get_cdgfxyrz_sbi(av[1], input)) != SUCCESS && r == BAD_INFILE))
	(void)av;
	if (ac != 1 ||
		((r = get_cdgfxyrz_sbi("42.fdf", input)) != SUCCESS && r == BAD_INFILE))
		r = usage();
	else if (r == SUCCESS &&
		(r = make_scene(input, &s)) == SUCCESS &&
		(r = add_default_iso_v(&v, s)) == SUCCESS)
	{
printf("passed init\n");fflush(0);
		tssv_apply_projs(v);
printf("passed projs\n");fflush(0);
		print_active_objects(v);
printf("passed print active\n");fflush(0);
		activate_view(v);
printf("view activated\n");fflush(0);
		print_scene_points(s);
		//s->v->out_fd = 1;
		//printf("\nPRINTING AS ASCII :\n");
		//tssv_print_ascii(s->v);
printf("entering loop\n");fflush(0);
		mlx_loop(s->mlx);
	}
	scene_teardown(&s);	
	if (r != SUCCESS)
		report_error(r);
	return (r);
}
