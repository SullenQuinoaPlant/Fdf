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
	t_s_s	*scene;

	if (ac == 1)
		return (0);
	input[1] = 0;
	if (get_cdgfxyrz_sbi(av[1], input) == SUCCESS &&
		make_scene(input, &scene) == SUCCESS &&
		add_isometric_v((t_vpos){110, 510}, (t_zntr){0.01, 0, 0, 0}, scene) == SUCCESS)
	{
		print_scene_points(scene);
		printf("\n");
		tssv_print_ascii(scene->v);
	}
	scene_teardown(&scene);	
	return (0);
}
