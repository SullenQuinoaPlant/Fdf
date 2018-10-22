#include "parse.h"

#define TIP_CT 8

static void						set_mm_from_int(
	int in[DIMS][MIN_MAX_SZ],
	double ret[DIMS][MIN_MAX_SZ])
{
	int		i;
	int		j;

	i = -1;
	while (++i < DIMS)
	{
		ret[i][MIN] = in[i][MIN];
		ret[i][MAX] = in[i][MAX];
	}
}

void							cdgfxyrz_set_sbi_minmax(
	t_s_cdgfxyrz *p,
	t_s_sbi *sbi)
{
	t_xyz		extr[TIP_CT];
	double		mm[DIMS][MIN_MAX_SZ];


	ft_memcpy(ret[X][MIN], (t_xyz){0, 0, par[0][0].z}, sz);
	ft_memcpy(ret[X][MAX], (t_xyz){x - 1, y - 1, par[x][y].z}, sz);
}
