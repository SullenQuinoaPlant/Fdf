#include "scene_typedefs.h"
#include "discrete_ratio_tracking.h"

t_argb							truint_dec_to_targb(
	t_ruint *dec)
{
	t_argb	col;
	int		i;

	i = -1;
	col = 0;
	while (++i < ARGBS)
	{
		col <<= ARGB_SHIFT;
		col |= dec[i];
	}
	return (col);
}
