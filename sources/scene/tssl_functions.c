#include "scene.h"

static int				add_l_ar(
	t_s_sl *p)
{
	t_s_l	**ar;
	t_s_l	*q;
	t_list	*tl;
	size_t	sz;

	if ((ar = malloc((p->ar_sz + 1) * sizeof(t_s_l*))) &&
		(ar[p->ar_sz] = malloc(sizeof((sz = t_s_l * TAS)))) &&
		(tl = ft_lstnew(&(t_s_fsd){(q = ar[p->ar_sz]), q}, sizeof(t_s_fsp))))
	{
		((t_s_fsp*)tl->content)->last += TAS - 1;
		ft_lstadd(&p->nxt, tl);
		ft_bzero(ar[p->ar_sz], sz);
		ft_memcpy(ar, p->ar, (sz = p->ar_sz++ * sizeof(t_s_l*)));
		ft_cleanfree(p->ar, sz);
		p->ar = ar;
		return (SUCCESS);
	}
	if (ar[p->ar_sz])
		free(ar[p->ar_sz]);
	if (ar)
		free(ar);
	return (SYS_ERR);
}

int						init_tssl(
	t_s_sl *p)
{
	t_s_fsd const	last_link = (t_s_fsd){0, 0};
	t_list			*p;

	if (!(p = ft_lstnew(&last_link, sizeof(t_s_fsd))))
		return (SYS_ERR);
	p->nxt = p;
	p->ar_sz = 0;
	return (add_p_ar(p));
}

void				free_tssl(
	t_s_sl *lines)
{
	t_s_l *const	lim = *lines->ar + lines->ar_sz;
	t_s_l			*p;

	p = *lines->ar;
	while (p < lim)
		ft_cleanfree(p, TAG_AR_SZ * sizeof(t_s_l));
	ft_cleanfree(lines->ar, sizeof(t_s_l*) * lines->ar_sz);
	ft_lstdel(lines->nxt, ft_cleanfree);
}

int						get_nxt_l(
	t_s_s *scene,
	t_s_l **p_ret;
{
	t_s_sl *const	p = scene->lines;
	t_s_fsd			*fd;

	*p_ret = 0;
	while (!(fd = (t_s_fsp*)p->nxt->content))
		if ((r = add_p_ar(p)) != SUCCESS)
			return (r);
	if ((*p_ret = fd->free++) == fd->last)
		ft_lstdelhead(&p->nxt);
	return (SUCCESS);
}
