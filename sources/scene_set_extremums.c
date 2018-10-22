#include "scene.h"
#include <float.h>

/*
**It it assumed that the structure has previously been zeroed
*/
void						scene_init_extr(
	t_s_s *s)
{
	int		i;

	i = -1;
	while (++i < DIMS)
	{
		s->minmax[MIN][i] = DBL_MAX;
		s->minmax[MAX][i] = -DBL_MAX;
	}
}

void						scene_set_extr(
	t_s_s *s)
{
	minmax_permute(s->minmax, s->extr);
	barycenter(s->extr, MMXYZPC, s->extr_bar);
}
