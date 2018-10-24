#include <float.h>
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

static int				add_mlx_ptrs(
	t_vuint h,
	t_vuint w,
	t_s_sv *v)
{
	t_s_s *const	s = v->s;

}

static int				add_pxl_ars(
	t_vuint h,
	t_vuint w,
	t_s_sv *v)
{
	size_t const	sz = sizeof(double) * h * w;
	double			*p;
	size_t			ct;

	if (sz > PAC - v->s->pxl_allocs)
		return (MEM_CAP);
	if ((p = malloc(ct * sizeof(double))))
	{
		v->s->pxl_allocs -= sz;
		while (ct--)
			p[ct] = DBL_MAX;
		v->h = h;
		v->w = w;
		v->pxl_prec = p;
		return (SUCCESS);
	}
	return (SYS_ERR);
}

static int				init_view(
	t_s_s *s,
	t_vpos const hw,
	t_s_sv *v)
{
	int		r;

	ft_bzero(&v->id, sizeof(t_s_v) - sizeof(t_s_ring));
	if ((r = mirror_tsses(s, v) == SUCCESS) &&
		(r = add_mlx_ptrs(hw[V_H], hw[V_W], v) == SUCCESS))
		r = add_pxl_ars(hw[V_H], hw[V_W], v);
	v->s = s;
	v->ao = s->ao;
	v->out_fd = -1;
	return (r);
}

int						add_view(
	t_s_s *s,
	t_vpos const hw,
	t_s_sv **ret)
{
	t_s_sv	dummy;
	t_s_sv	*p;
	int		r;

	if (ret)
		*ret = 0;
	disable_scene_looping(s);
	if ((r = init_view(s, hw, &dummy)) == SUCCESS &&
		(wait_scene_not_looping(s) || (1)) &&
		(p = ring_expand(sizeof(t_s_sv), dummy, (void**)s->v)))
		p->id = (p->ring.prv == (t_ring)p) ? 0 : ((t_s_sv*)v->ring.prv)->id + 1;
	else
	{
		r = SYS_ERR;
		free_view_members(&dummy);
	}
	enable_sceen_looping(s);
	return (r);
}
