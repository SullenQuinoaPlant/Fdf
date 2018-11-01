#include "scene.h"
#include "discrete_ratio_tracking.h"

t_argb						truint_dec_to_targb(
	t_ruint *dec,
	t_ruint dt)
{
	t_ruint const	offset = dt + 1;
	t_argb			col;
	int				i;

	i = -1;
	col = 0;
	while (++i < ARGBS)
	{
		col <<= ARGB_SHIFT;
		col |= *dec;
		dec += offset;
	}
	return (col);
}
