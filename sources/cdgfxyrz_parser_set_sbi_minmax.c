#include "parse.h"

void							cdgfxyrz_set_sbi_minmax(
	t_s_cdgfxyrz *p,
	t_s_sbi *sbi)
{
	t_xyz (*const		ret)[MIN_MAX_SZ] = sbi->minmax;
	t_s_cxyd (*const	par)[p->y_sz] = (t_s_cxyd(*)[p->y_sz])p->ar;
	size_t const		sz = sizeof(t_xyz);
	int					x;
	int					y;

	ft_memcpy(ret[X][MIN], (t_xyz){0, 0, par[0][0].z}, sz);
	ft_memcpy(ret[X][MAX], (t_xyz){x - 1, y - 1, par[x][y].z}, sz);
}
