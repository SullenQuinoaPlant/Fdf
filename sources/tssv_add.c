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
	if ((p2 = malloc(ct * sizeof(double))))
	{
		v->s->pxl_allocs -= sz;
		while (ct--)
			p[ct] = DBL_MAX;
		v->h = h;
		v->w = w;
		v->pxl = p1;
		v->pxl_prec = p2;
		return (SUCCESS);
	}
	if (p1)
		free(p1);
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
	v->id = (v->ring.prv == (t_ring)v) ? 0 : ((t_s_sv*)v->ring.prv)->id + 1;
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
	t_s_sv	**v;
	int		r;

	if (ret)
		*ret = 0;
	r = SYS_ERR;
	v = &s->v;
	disable_updates();
	if (ring_expand(sizeof(t_s_sv), 0, (void**)v))
	{
		if ((r = init_view(s, hw, *v)) != SUCCESS)
			free_view(v);
		else if (ret)
			*ret = *v;
	}
	enable_updates();
	return (r);
}
