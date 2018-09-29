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

static void				free_view_members(
	void *view,
	size_t unused)
{
	t_s_sv *const	v = (t_s_sv*)view;
	t_s_prj *		prj;

	(void)unused;
	prj = v->proj;
	while (prj)
	{
		prj->refs--;
		prj = prj->up;
	}
	ring_free(sizeof(t_s_aq), free_ao, &v->ao);
	if (stuff && stuff_del)
		(*stuff_del)(stuff, stuff_sz);
	ft_bzero(v, sizeof(t_s_sv));
}

static void				free_view(
	t_s_sv *ring_bit)
{
	ring_shrink(sizeof(t_s_sv), free_view_members, &ring_bit);
}

void					free_views(
	t_s_sv *ring)
{
	ring_free(sizeof(t_s_sv), free_view_members, &ring);
}
