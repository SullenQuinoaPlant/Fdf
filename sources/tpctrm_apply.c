#include "scene.h"

void							tpctrm_apply(
	t_pctrm ct,
	t_xyz const in,
	t_xyz ret)
{
	int		i;
	int		j;

	ft_memcpy(ret, ct[TPCTRM_TR], sizeof(t_xyz));
	i = -1;
	while (++i < DIMS)
	{
		j = -1;
		while (++j < DIMS)
			ret[i] += in[j] * ct[j][i];
	}
}
