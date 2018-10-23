#include "scene_typedefs.h"
#include <float.h>

void							minmax_init(
	t_xyz mm[MIN_MAX_SZ])
{
	int		i;

	i = -1;
	while (++i < DIMS)
	{
		mm[MIN][i] = DBL_MAX;
		mm[MAX][i] = -DBL_MAX;
	}
}

void							minmax_permute(
	t_xyz mm[MIN_MAX_SZ],
	t_xyz *ret)
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
				(*ret)[X] = mm[i][X];
				(*ret)[Y] = mm[j][Y];
				(*ret)[Z] = mm[k][Z];
				ret++;
			}
		}
	}
}

void						minmax_set(
	t_xyz *pts,
	size_t pt_ct,
	t_xyz mm[MIN_MAX_SZ])
{
	double	d;

	minmax_init(mm);
	while (pt_ct--)
	{
		if ((d = (*pts)[X]) < mm[MIN][X])
			mm[MIN][X] = d;
		if (d > mm[MAX][X])
			mm[MAX][X] = d;
		if ((d = (*pts)[Y]) < mm[MIN][Y])
			mm[MIN][Y] = d;
		if (d > mm[MAX][Y])
			mm[MAX][Y] = d;
		if ((d = (*pts)[Z]) < mm[MIN][Z])
			mm[MIN][Z] = d;
		if (d > mm[MAX][Z])
			mm[MAX][Z] = d;
		pts++;
	}
}
