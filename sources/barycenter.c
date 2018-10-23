#include "functions.h"

#define TMP_SZ 5

void							barycenter(
	t_xyz *pts,
	int pt_ct,
	t_xyz ret)
{
	t_xyz	tmp[TMP_SZ];
	int		tmp_ct[TMP_SZ];
	int		i;
	int		j;

	i = -1;
	while (++i < TMP_SZ)
		tmp_ct[i] = pt_ct / TMP_SZ;
	i = pt_ct % TMP_SZ;
	while (i--)
		tmp_ct[i]++;
	i = -1;
	while (++i < TMP_SZ)
		barycenter(pts + (i ? tmp_ct[i] : 0), tmp_ct[i], tmp[i]);
	i = -1;
	ft_bzero(ret, sizeof(t_xyz));
	while (++i < pt_ct)
	{
		j = -1;
		while (++j < DIMS)
			ret[j] += tmp_ct[i] * tmp[i][j];
	}
	mult_dbl_ar(1.0 / (double)pt_ct, DIMS, ret);
}
