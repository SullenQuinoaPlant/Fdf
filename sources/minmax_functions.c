#include <float.h>

void							minmax_init(
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

void							minmax_permute(
	t_xyz mm[MIN_MAX_SZ],
	t_xyz ret[MIN_MAX_XYZ_PERMUTATION_COUNT])
{
	int		i;
	int		j;
	int		k;

	i = -1;
	while (++i < MIN_MAX_SZ)
	{
		j = -1;
		while (++j < MIN_MAX_SZ)
		{
			k = -1;
			while (++k < MIN_MAX_SZ)
			{
				ret[X] = mm[i][X];
				ret[Y] = mm[j][Y];
				ret[Z] = mm[k][Z];
				ret++;
			}
		}
	}
}
