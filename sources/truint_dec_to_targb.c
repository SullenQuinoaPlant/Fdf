#include "scene_typedefs.h"
#include "discrete_ratio_tracking.h"

void							truint_dec_to_targb(
	t_ruint *dec,
	t_argb *ret)
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
	*ret = col;
}
