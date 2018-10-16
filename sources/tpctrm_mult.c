include "scene_typedefs.h"

void					tpctrm_mult(
	t_pctrm const a,
	t_pctrm const b,
	t_pctrm c)
{
	int		i;
	int		j;

	ft_bzero(c, sizeof(t_pctrm));
	i = -1;
	while (++i < DIMS_N_TR)
	{
		j = -1;
		while (++j < DIMS)
		{
			k = -1;
			while (++k < DIMS)
				c[i][j] += a[i][k] * b[k][j];
		}
	}
	i = -1;
	while (++i < DIMS)
		c[TR][i] += b[TR][i];
}
