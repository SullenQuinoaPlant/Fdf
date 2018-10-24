#include "functions.h"
#include "scene.h"

int						get_nxt_se(
	t_e_seg g,
	t_s_s *s,
	t_tag *ret,
	void **ret_addr)
{
	t_s_se *const	p = &s->e[g];
	t_s_ft			*tags;
	t_tag			tag;
	int				r;

	if (!p->nxt->next &&
		(r = add_star(g, s)) != SUCCESS)
			return (r);
	tags = (t_s_ft*)p->nxt->content;
	if ((tag = tags->free++) == tags->last)
	{
		ft_lstdelhead(&p->nxt, ft_cleanfree);
		s->nxt_allocs -= sizeof(t_list);
	}
	*ret = tag;
	if (ret_addr)
		*ret_addr = (p->ar[tag >> TPS]) + (tag & TPM) * teseg_type_sz(g);
	return (SUCCESS);
}
