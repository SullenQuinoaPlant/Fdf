#include "functions.h"
#include "scene.h"

int						init_tsse(
	t_e_seg g,
	t_s_se *se,
	t_s_s *s)
{
	t_s_ft const	last_link = (t_s_ft){0, 0};
	t_list			*tl;

	if (!(tl = ft_lstnew(&last_link, sizeof(t_s_ft))))
		return (SYS_ERR);
	se->nxt = tl;
	se->ar_sz = 0;
	se->e_sz = teseg_type_sz(g);
	return (add_star(g, s));
}

int						init_tsses(
	t_s_s *s)
{
	t_e_seg	i;
	int		r;

	i = e_p;
	while (i < e_seg_sz && (r = init_tsse(i, &s->e[i], s)) == SUCCESS)
		i++;
	return (r);
}

void					free_tsse(
	t_s_se *se,
	t_s_s *s)
{
	free_tar(se->ar, se->ar_sz, se->e_sz, s);
	ft_lstdel(&se->nxt, ft_cleanfree);
}

void					free_tsses(
	t_s_s *s)
{
	t_e_seg		i;

	i = e_p;
	while (i < e_seg_sz)
		free_tsse(&s->e[i++], s);
}
