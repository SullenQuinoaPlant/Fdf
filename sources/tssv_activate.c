#include "functions.h"
#include "scene.h"

void						activate_view(
	t_s_sv *v)
{
	t_s_s *const	s = v->s;
	t_s_sv			*prv;

	if ((prv = s->av) != v)
	{
		if (prv)
			deactivate_view(prv);
		s->av = v;
	}
	if (v->vt == e_iso)
		v->e[e_p].prj = point_projection_iso_persist;
}
