#include "scene.h"

int						init_se(
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
