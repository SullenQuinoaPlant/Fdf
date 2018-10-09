#include "scene.h"

size_t					teseg_type_sz(
	t_e_seg g)
{
	if (g == e_spnv)
		return (sizeof(t_u_spsv));
	if (g == e_sd)
		return (sizeof(t_s_d));
	if (g == e_slna)
		return (sizeof(t_u_slsa));
	if (g == e_sf)
		return (sizeof(t_s_f));
	if (g == e_so)
		return (sizeof(t_s_o));
	return (0);
}

int						init_tsse(
	t_e_seg g,
	t_s_se *se)
{
	t_s_ft const	last_link = (t_s_ft){0, 0};
	t_list			*tl;

	if (!(tl = ft_lstnew(&last_link, FT_SZ)))
		return (SYS_ERR);
	se->nxt = tl;
	se->ar_sz = 0;
	se->e_sz = teseg_type_sz(g);
	return (add_star(se, s));
}

void					free_tsse(
	t_s_se *se)
{
	free_tar(se->ar, se->ar_sz, se->e_sz);
	ft_lstdel(&se->nxt, ft_cleanfree);
}

int						get_nxt_se(
	t_e_seg g,
	t_s_s *s,
	t_tag *ret,
	void **ret_addr)
{
	t_s_se *const	p = s->e[g];
	t_s_ft			tags;
	t_tag			tag;
	int				r;

	if (!p->nxt->next &&
		(r = add_tar(s, g)) != SUCCESS)
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
	t_s_s *s,
	t_e_seg g)
{
	t_tag const	last = first + diff_with_last;
	t_list		*tl;
	int			r;

	
	if (!(tl = ft_lstnew(&(t_s_ft){first, last}, sizeof(t_s_ft))))
		return (SYS_ERR);
	ft_lstadd(&s->e[g]->nxt, tl);
	r = SUCCESS;
	if ((s->nxt_allocs += sizeof(t_list)) >= TAG_NXT_CAP)
		r = realloc_tars(s);//this is heavy. do it later.
	return (r);
}
