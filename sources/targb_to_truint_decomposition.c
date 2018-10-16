#include "scene_typedefs.h"
#include "discrete_ratio_tracking.h"

void							targb_pair_to_tdni(
	t_argb argb1,
	t_argb arbg2,
	t_delta_n_init *ret)
{
	int		i;
	t_ruint	c;

	i = -1;
	while (++i < ARGBS)
	{
		c = argb1 & ARGB_MASK;
		dec[i][INIT] = c;
		dec[i][DT] = argb2 & ARGB_MASK - c;
		argb1 >> ARGB_SHIFT;
		argb2 >> ARGB_SHIFT;
	}
}
