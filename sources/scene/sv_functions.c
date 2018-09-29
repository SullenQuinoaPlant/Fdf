#include "scene.h"

static int				init_view(
	t_s_s *s,
	t_s_v *v)
{
	int		r;

	if ((r = ring_clone(sizeof(t_s_ao), s->ao, &v->ao)) == RING_SUCCESS)
	{
		v->id = (void*)v->ring->prv != (void*)v ? v->ring->nxt + 1;
		v->ao_cursor = v->ao;
	}
}

int						new_view(
	t_s_s *s,
	t_viewbuilder f,
	void *f_arg,
	t_s_v **ret)
{
	t_s_v	*v;
	int		r;

	ret = 0;
	r = SYS_ERR;
	if (ring_expand(sizeof(t_s_v), 0, &s->views) == RING_SUCCESS ||
		(r = init_view(s, v)) == SUCCESS ||
		(r = (*f)(f_arg, s, v)) == SUCCESS)
		*ret = v;
	return (r);
}
