#include "scene.h"

void						obj_projection(
	t_s_sv *v,
	void *obj,
	t_s_pp const *const *points,
	void *projection)
{
	t_s_o *const	o = (t_s_o*)obj;
	t_s_op *const	op = (t_s_op*)projection;

	(void)points;
	op->set_flgs = 0;
	op->un_flgs = ~(uint8_t)0;
}
