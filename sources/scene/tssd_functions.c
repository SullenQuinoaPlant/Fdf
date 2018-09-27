#include "scene.h"

static int				add_d_ar(
	t_s_sd *p)
{
	t_s_d	**ar;
	t_s_d	*q;
	t_list	*tl;
	size_t	sz;

	if ((ar = malloc((p->ar_sz + 1) * sizeof(t_s_d*))) &&
		(ar[p->ar_sz] = malloc(sizeof((sz = t_s_d * TAS)))) &&
		(tl = ft_lstnew(&(t_s_fsd){(q = ar[p->ar_sz]), q}, sizeof(t_s_fsp))))
	{
		((t_s_fsp*)tl->content)->last += TAS - 1;
		ft_lstadd(&p->nxt, tl);
		ft_bzero(ar[p->ar_sz], sz);
		ft_memcpy(ar, p->ar, (sz = p->ar_sz++ * sizeof(t_s_d*)));
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

int						init_tssd(
	t_s_sd *p)
{
	t_s_fsd const	last_link = (t_s_fsd){0, 0};
	t_list			*p;

	if (!(p = ft_lstnew(&last_link, sizeof(t_s_fsd))))
		return (SYS_ERR);
	p->nxt = p;
	p->ar_sz = 0;
	return (add_p_ar(p));
}

void				free_tssd(
	t_s_sd *dots)
{
	t_s_d *const	lim = *dots->ar + dots->ar_sz;
	t_s_d			*p;

	p = *dots->ar;
	while (p < lim)
		ft_cleanfree(p, TAG_AR_SZ * sizeof(t_s_d));
	ft_cleanfree(dots->ar, sizeof(t_s_d*) * dots->ar_sz);
	ft_lstdel(dots->nxt, ft_cleanfree);
}

int						get_nxt_d(
	t_s_s *scene,
	t_s_d **p_ret;
{
	t_s_sd *const	p = scene->dots;
	t_s_fsd			*fd;

	*p_ret = 0;
	while (!(fd = (t_s_fsp*)p->nxt->content))
		if ((r = add_p_ar(p)) != SUCCESS)
			return (r);
	if ((*p_ret = fd->free++) == fd->last)
		ft_lstdelhead(&p->nxt);
	return (SUCCESS);
}
