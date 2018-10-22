#include "scene.h"

size_t					teseg_type_sz(
	t_e_seg g)
{
	size_t const	sizes[e_seg_sz] = {
		sizeof(t_s_p),
		sizeof(t_s_d),
		sizeof(t_s_l),
		sizeof(t_s_a),
		sizeof(t_s_f),
		sizeof(t_s_o)};

	if (g == e_seg_null)
		return (0);
	return (sizes[g]);
}
