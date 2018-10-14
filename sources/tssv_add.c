#include "scene.h"

static int				mirror_tsses(
	t_s_s *s,
	t_s_sv *v)
{
	int		i;
	size_t	e_sz;
	int		r;

	i = -1;
	while (++i < e_seg_sz)
	{
		e_sz = get_ve_size(i);
		if ((r = mirror_tsta(s, &s->e[i], e_sz, &v->e[i])) != SUCCESS)
			break ;
	}
	return (r);
}

static int				init_view(
	t_s_s *s,
	t_s_sv *v)
{
	int		r;

	ft_bzero(&v->id, sizeof(t_s_v) - sizeof(t_s_ring));
	v->id = (v->ring.prv == (t_ring)v) ? 0 : ((t_s_sv*)v->ring.prv)->id + 1;
	v->s = s;
	v->ao = s->ao;
	if ((r = mirorr_tsses(s, v)) == SUCCESS)
		copy_tsta(s->e[e_spnv].ta, v->e[e_spnv].ar);
	return (r);
}

int						add_view(
	t_s_s *s,
	t_s_sv **ret)
{
	t_s_sv	*v;
	int		r;

	*ret = 0;
	r = SYS_ERR;
	v = s->v;
	if (ring_expand(sizeof(t_s_sv), 0, (void**)&s->v) == RING_SUCCESS &&
		(r = init_view(s, v)) == SUCCESS)
		*ret = s->v;
	else if (s->v != v)
		ring_shrink(sizeof(t_s_v), free_view_members, (void**)&s->v);
	return (r);
}
