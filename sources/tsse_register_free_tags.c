#include "functions.h"
#include "scene.h"

int						reg_tsse_freetags(
	t_tag first,
	t_tag diff_with_last,
	t_s_s *s,
	t_s_se *g)
{
	t_tag const	last = first + diff_with_last;
	t_list		*tl;
	int			r;

	
	if (!(tl = ft_lstnew(&(t_s_ft){first, last}, sizeof(t_s_ft))))
		return (SYS_ERR);
	ft_lstadd(&g->nxt, tl);
	r = SUCCESS;
	if ((s->nxt_allocs += sizeof(t_list)) >= TAG_NXT_CAP)
		r = realloc_tars(s);
	return (r);
}

int						reg_teseg_freetags(
	t_tag first,
	t_tag diff_with_last,
	t_s_s *s,
	t_e_seg g)
{
	t_s_se *const	grp = &s->e[g];

	return (reg_tsse_freetags(first, diff_with_last, s, grp));
}
