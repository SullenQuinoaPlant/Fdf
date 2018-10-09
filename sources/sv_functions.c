#include "scene.h"

static int				init_view(
	t_s_s *s,
	t_s_sv *v)
{
	int		r;

	ft_bzero(&v->id, sizeof(t_s_v) - sizeof(t_s_ring));
	v->id = (v->ring->prv == v) ? 0 : ((t_s_v*)v->ring->prv)->id + 1;
	v->s = s;
	v->ao = s->ao;
	r = clone_tar(&s->e[e_spnv].ta, &v->vpnv);
	return (r);
}

int						new_view(
	t_s_s *s,
	t_s_sv **ret)
{
	t_s_v	*v;
	int		r;

	*ret = 0;
	r = SYS_ERR;
	v = s->v;
	if (ring_expand(sizeof(t_s_v), 0, &s->v) == RING_SUCCESS &&
		(r = init_view(s, v)) == SUCCESS)
		*ret = s->v;
	else if (s->v != v)
		ring_shrink(sizeof(t_s_v), ft_cleanfree, &s->v);
	return (r);
}
