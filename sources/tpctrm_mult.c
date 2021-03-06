#include "scene_typedefs.h"
#include "scene.h"

void					set_tpctrm_identity(
	t_pctrm ret)
{
	t_pctrm const	id = {
		{1, 0, 0},
		{0, 1, 0},
		{0, 0, 1},
		{0, 0, 0}};

	ft_memcpy(ret, id, sizeof(t_pctrm));
}

void					tpctrm_mult(
	t_pctrm const a,
	t_pctrm const b,
	t_pctrm c)
{
	int		i;
	int		j;
	int		k;

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
		c[TPCTRM_TR][i] += b[TPCTRM_TR][i];
}

void					tpctrm_scalar_mult(
	double scalar,
	t_pctrm c)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	while (++i < DIMS_N_TR)
	{
		j = -1;
		while (++j < DIMS)
		{
			k = -1;
			while (++k < DIMS)
				c[i][j] *= k;
		}
	}
	i = -1;
	while (++i < DIMS)
		c[TPCTRM_TR][i] *= scalar;
}
