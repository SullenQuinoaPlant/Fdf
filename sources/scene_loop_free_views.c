 "functions.h"
#include "scene.h"

int						register_view_release(
	t_s_sv *v,
	t_s_s *s)
{
	t_list	*p;
	int		r;

	if (!(p = ft_lstnew(&v, sizeof(t_s_sv*))))
		return (SYS_ERR);
	ft_lstadd(&s->v_rel, p);
	return (SUCCESS);
}

static void				release_view(
	t_list *p_view)
{
	t_s_sv	*p;

	p = p_view->content;
	free_view(&p);
	p_view->content = 0;
}

/*
**We don't free first element because a new call to
**	register_view_release may have happened
**	concurrently,
**	creating a structure with a pointer to list head.ç
*/
void					scene_loop_free_views(
	t_s_s *s)
{
	t_list *const	p = s->v_rel;

	ft_lstiter(p, release_view);
	if (p->next)
		ft_lstdel(&p->next);
}
