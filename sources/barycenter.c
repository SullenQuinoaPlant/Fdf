#include "functions.h"

#define TMP_SZ 5

static void						set_tmp_ct(
	int pt_ct,
	int *tmp_ct)
{
	int		i;

	i = -1;
	while (++i < TMP_SZ)
		tmp_ct[i] = pt_ct / TMP_SZ;
	i = pt_ct % TMP_SZ;
	while (i--)
		tmp_ct[i]++;
}

void							barycenter(
	t_xyz *pts,
	int const pt_ct,
	t_xyz ret)
{
	int		average_lim = pt_ct < TMP_SZ ? pt_ct : TMP_SZ;
	t_xyz	tmp[TMP_SZ];
	int		tmp_ct[TMP_SZ];
	int		i;

	set_tmp_ct(pt_ct, tmp_ct);
	i = -1;
	while (++i < TMP_SZ)
		if (tmp_ct[i] == 1)
			ft_memcpy(&tmp[i], pts[i], sizeof(t_xyz));
		else if (tmp_ct[i])
			barycenter(pts + (i ? tmp_ct[i] : 0), tmp_ct[i], tmp[i]);
	ft_bzero(ret, sizeof(t_xyz));
	i = -1;
	while (++i < average_lim)
	{
		ret[X] += (double)tmp_ct[i] * tmp[i][X];
		ret[Y] += (double)tmp_ct[i] * tmp[i][Y];
		ret[Z] += (double)tmp_ct[i] * tmp[i][Z];
	}
	mult_dbl_ar(1.0 / (double)pt_ct, DIMS, ret);
}
