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

int					clone_s_ao(
	t_s_s *s,
	t_s_ao **ret)
{
	t_s_ao *const	lim = s->ao;
	t_s_ao			*ao;
	t_s_ao			*petri;
	int				r;

	*ret = 0;
	if (!lim)
		return (SUCCESS);
	petri = 0;
	while ((r = ring_expand(sizeof(t_s_ao), ao, &petri) == RING_SUCCESS &&
		ao != lim)
		ao = 
		v = (t_s_sv*)v.ring.nxt;
	return (SUCCESS);

}
