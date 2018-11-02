#include "outer.h"

void						set_mult_pnt_dec(
	double src[PNT_DEC_SZ],
	double deltas[PNT_DEC_SZ],
	double ratio,
	double dest[PNT_DEC_SZ])
{
	int		i;

	ft_memcpy(dest, src, sizeof(double) * PNT_DEC_SZ);
	i = -1;
	while (++i < PNT_DEC_SZ)
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
