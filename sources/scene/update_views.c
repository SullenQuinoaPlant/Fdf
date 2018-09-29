#include "scene.h"

/*
**update all scene views one active objects
*/
int					update_sv_one_ao(
	t_s_s *s)
{
	t_s_sv *const	lim = s->views;
	t_s_ao *const	ao = s->ao;
	t_s_sv			*v;
	int				r;

	if (!(v = s->views))
		return (SUCCESS);
	while ((r = ring_expand(sizeof(t_s_ao), ao, &v->ao)) == RING_SUCCESS &&
		v != lim)
		v = (t_s_sv*)v.ring.nxt;
	return (SUCCESS);
}
