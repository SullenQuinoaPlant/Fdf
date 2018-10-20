#include "functions.h"
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
		if ((r = mirror_tsta(s, &s->e[i].ta, e_sz, &v->e[i].ta)) != SUCCESS)
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
	r = mirror_tsses(s, v);
	v->out_fd = -1;
	v->out_wdw = 0;
	return (r);
}

int						add_view(
	t_s_s *s,
	t_s_sv **ret)
{
	t_s_sv	**v;
	int		r;

	if (ret)
		*ret = 0;
	r = SYS_ERR;
	v = &s->v;
	if (ring_expand(sizeof(t_s_sv), 0, (void**)v) == RING_SUCCESS)
	{
		if ((r = init_view(s, *v)) != SUCCESS)
			free_view(v);
		else if (ret)
			*ret = *v;
	}
	return (r);
}
