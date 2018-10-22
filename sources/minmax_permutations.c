#include "scene.h"

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
