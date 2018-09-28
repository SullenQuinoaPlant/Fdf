#include "scene.h"

void					add_view(
	t_s_v const *v,
	t_s_s 		*s)
{
	t_s_sv	*p;
	t_s_sv	*pp;
	int		r;

	if (!(p = malloc(sizeof(t_s_sv))))
		return (SYS_ERR);
	if ((pp = s->views))
	{
		*p = (t_s_sv){v, pp->nxt, pp};
		pp->nxt->prev = p;
		pp->nxt = p;
	}
	else
		s->views = (t_s_sv){v, p, p};
}

int						new_view(
	t_s_v **ret)
{

	if (!(*ret = malloc(sizeof(t_s_v))))
		return (SYS_ERR);
	ft_bzero(*ret, sizeof(t_s_v));
	return (SUCCESS);
}
