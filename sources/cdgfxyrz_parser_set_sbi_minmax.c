#include "parse.h"
#include "functions.h"

static void						set_mm(
	t_s_cdgfxyrz *p,
	t_xyz ret[MMXYZPC])
{
	ret[MIN][X] = 0;
	ret[MIN][Y] = 0;
	ret[MIN][Z] = p->zmm[MIN];
	ret[MAX][X] = p->x_sz - 1;
	ret[MAX][Y] = p->y_sz - 1;
	ret[MAX][Z] = p->zmm[MAX];
}

static void						adjust_minmax(
	t_xyz bar,
	t_xyz *mm,
	t_xyz *sbi_mm)
{
	int		i;
	int		j;

	i = -1;
	while (++i < DIMS)
	{
		j = -1;
		while (++j < MIN_MAX_SZ)
			sbi_mm[j][i] = mm[j][i] - bar[i];
	}
}

void							cdgfxyrz_set_sbi_minmax(
	t_s_cdgfxyrz *p,
	t_s_sbi *sbi)
{
	t_xyz		mm[MIN_MAX_SZ];
	t_xyz		extr[MMXYZPC];
	t_xyz		bar;

	set_mm(p, mm);
	minmax_permute(mm, extr);
	barycenter(extr, MMXYZPC, bar);
	adjust_minmax(bar, mm, sbi->minmax);
	ft_memcpy(p->at, bar, sizeof(t_xyz));
}
