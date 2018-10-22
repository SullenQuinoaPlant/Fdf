#include "scene.h"

void						deactivate_view(
	t_s_sv *v)
{
	v->e[e_p].prj = point_projection;
}
