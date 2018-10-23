#include <float.h>

void						minmax_init(
	t_xyz mm[MIN_MAX_SZ])
{
	int		i;

	i = -1;
	while (++i < DIMS)
	{
		s->minmax[MIN][i] = DBL_MAX;
		s->minmax[MAX][i] = -DBL_MAX;
	}
}
