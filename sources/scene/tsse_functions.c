#include "scene.h"

int						init_tsse(
	t_s_se *se)
{
	t_s_ft const	last_link = (t_s_ft){0, 0};
	t_list			*tl;

	if (!(tl = ft_lstnew(&last_link, FT_SZ)))
		return (SYS_ERR);
	se->nxt = tl;
	se->ar_sz = 0;
	return (add_star(se, s));
}

void					free_tsse(
	t_s_se *se)
{
	size_t const	sz = TAS * se->e_sz;
	void **const	lim = se->ar + se->ar_sz;
	void			**p;

	p = se->ar;
	while (p < lim)
		ft_cleanfree(*p++, sz);
	ft_cleanfree(se->ar, sizeof(void*) * se->ar_sz);
	ft_lstdel(&se->nxt, ft_cleanfree);
}

int						get_nxt_se(
	t_e_seg grp,
	t_s_s *s,
	t_tag *ret,
	void **ret_addr)
{
	t_s_se *const	p = s->es[grp];
	t_s_ft			tags;
	t_tag			tag;
	int				r;

	if (!p->nxt->next &&
		(r = add_tar(s, grp)) != SUCCESS)
			return (r);
	tags = (t_s_ft*)p->nxt->content;
	if ((tag = tags->free++) == tags->last)
	{
		ft_lstdelhead(&p->nxt);
		s->nxt_allocs -= sizeof(t_list);
	}
	*p_ret = tag;
	if (ret_addr)
		*ret_addr = (p->ar[tag >> TPS])[tag & TPM];
	return (SUCCESS);
}

int						reg_freetags(
	t_tag first,
	t_tag diff_with_last,
	t_s_s *scene,
	t_s_se *group)
{
	t_tag const	last = first + diff_with_last;
	t_list		*tl;
	int			r;

	
	if (!(tl = ft_lstnew(&(t_s_ft){first, last}, sizeof(t_s_ft))))
		return (SYS_ERR);
	ft_lstadd(&group->nxt, tl);
	r = SUCCESS;
	if ((scene->nxt_allocs += sizeof(t_list)) >= TAG_NXT_CAP)
		r = realloc_tars(s);//this is heavy. do it later.
	return (r);
}
