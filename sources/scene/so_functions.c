#include "scene.h"

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
		(r = ring_expand(sizeof(t_s_ao), 0, &s->ao) == RING_SUCCESS))
	{
		o->refs = 1;
		s->ao->flags |= SHOW_O;
	}
	return (r);
}
