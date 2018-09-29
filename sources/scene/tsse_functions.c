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

	if (!p->nxt->next)
	{
		if ((r = add_tar(p, s)) != SUCCESS ||
			(grp == e_spnv &&
			(r = realloc_prjs_pnv(s)) != SUCCESS))
			return (r);
	tags = (t_s_ft*)p->nxt->content;
	if ((tag = tags->free++) == tags->last)
	{
		ft_lstdelhead(&p->nxt);
		s->nxt_allocs--;
	}
	*p_ret = tag;
	if (ret_addr)
		*ret_addr = (p->ar[tag >> TPS])[tag & TPM];
	return (SUCCESS);
}
