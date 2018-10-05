#include "scene.h"

void				print_scene_points(
	t_s_s *s)
{
	t_s_se	*pts;
	t_s_p	*p;
	size_t	i;
	size_t	j;

	pts = &s->e[e_spnv];
	i = -1;
	while (++i < pts->ar_sz)
	{
		p = pts->ar[i];
		j = -1;
		while (++j < TAS)
			printf("xyz: %f %f %f\t", p->xyz[X], p->xyz[Y], p->xyz[Z]);
	}
}
