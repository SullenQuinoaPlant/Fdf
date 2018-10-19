#include "outer.h"

void						set_mult_pnt_dec(
	double src[DIMS + ARGBS],
	double deltas[DIMS + ARGBS],
	double ratio,
	double dest[DIMS + ARGBS])
{
	int		i;

	ft_memcpy(dest, src, sizeof(double) * PNT_DEC_SZ);
	i = -1;
	while (++i < DIMS + ARGBS)
		dest[i] += ratio * deltas[i];
}

void						set_mult_dims(
	double src[DIMS],
	double deltas[DIMS],
	double ratio,
	double dest[DIMS])
{
	int		i;

	ft_memcpy(dest, src, sizeof(double) * DIMS);
	i = -1;
	while (++i < DIMS)
		dest[i] += ratio * deltas[i];;
}
