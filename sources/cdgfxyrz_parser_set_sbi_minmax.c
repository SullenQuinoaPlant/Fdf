#include "parse.h"

static void						set_mm(
	t_s_cdgfxyrz *p,
	t_xyz ret[MMXPC])
{
	ret[MIN][X] = 0;
	ret[MIN][Y] = 0;
	ret[MIN][Z] = p->zmm[MIN];
	ret[MAX][X] = p->x_sz - 1;
	ret[MAX][Y] = p->y_sz - 1;
	ret[MAX][Z] = p->zmm[MAX];
}

void							cdgfxyrz_set_sbi_minmax(
	t_s_cdgfxyrz *p,
	t_s_sbi *sbi)
{
	t_xyz		mm[MIN_MAX_SZ];
	t_xyz		extr[MMXPC];
	t_xyz		bar;
	int			i;
	int			j;

	set_mm(p, mm);
	minmax_permute(mm, extr);
	barycenter(extr, MMXPC, bar);
	ft_memcpy(p->at, bar, sizeof(t_xyz));
	i = -1;
	while (++i < DIMS)
	{
		j = -1;
		while (++j < MIN_MAX_SZ)
			sbi->minmax[j][i] = mm[j][i] - bar[i];
	}
}
