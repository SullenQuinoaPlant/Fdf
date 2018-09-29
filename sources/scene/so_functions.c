#include "scene.h"

int						get_nxt_obj(
	t_s_s *scene,
	t_tag *ret,
	t_s_o **retaddr)
{
	t_s_so *const	p = scene->os;
	size_t const	sz = TAS * T_S;
	t_s_ft			*ftgs;
	int				r;

	while (!(ftgs = (t_s_fsp*)p->nxt->content))
		if ((r = TAC - scene->ar_allocs < sz ? MEM_CAP : 0) ||
			(r = add_star(add_obj_ar, sz, s)) != SUCCESS)
			return (r);
	if ((*ret = ftgs->free++) == fp->last)
	{
		ft_lstdelhead(&p->nxt);
		scene->nxt_allocs--;
	}
	if (retaddr)
		*retaddr = &(scene->os.ar[*ret >> TPS])[*ret & TPM];
	return (SUCCESS);
}

int						new_scene_obj(
	t_s_s *scene,
	t_s_o **ret,
	t_tag *ret_tag)
{
	t_tag	tag;
	t_s_o	*obj;
	int		r;

	*ret = 0;
	if ((r = get_nxt_obj(scene, &tag, &obj)) != SUCCESS ||
		(r = get_nxt_uspsv(scene, &tag)) != SUCCESS)
		return (r);
	ft_bzero(obj, sizeof(t_s_o));
	obj->refct = 1;
	if (ret_tag)
		*ret_tag = tag;
	return (r);
}
int						nxt_fresh_obj(
	t_s_s *scene,
	t_s_o **ret,
	t_tag *ret_tag)
{
	t_tag	tag;
	t_s_o	*obj;
	int		r;

	*ret = 0;
	if ((r = get_nxt_obj(scene, &tag, &obj)) != SUCCESS)
		return (r);
	ft_bzero(obj, sizeof(t_s_o));
	obj->h.type = e_eg_null;
	if (ret_tag)
		*ret_tag = tag;
	return (r);
}

int						nxt_active_obj(
	t_s_s *s,
	t_s_o **ret,
	t_tag *ret_tag)
{
	t_s_o	*o;
	int		r;

	if ((r = nxt_fresh_obj(s, ret, ret_tag)) == SUCCESS &&
		(r = ring_expand(sizeof(t_s_sao), 0, &s->ao) == RING_SUCCESS))
	{
		o->refs = 1;
		s->ao->flags |= SHOW_O;
		udpate_view_aos(s);
	}
	return (r);
}
