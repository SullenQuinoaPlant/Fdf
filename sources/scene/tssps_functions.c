#include "scene.h"

static int				add_p_ar(
	t_s_sp *p)
{
	t_s_p	**ar;
	t_list	*tl;
	size_t	sz;

	if ((ar = malloc((p->ar_sz + 1) * sizeof(t_s_p*))) &&
		(ar[p->ar_sz] = malloc(sizeof(t_s_p * TAS))) &&
		(tl = ft_lstnew(&(t_s_fsp){(q = ar[p->ar_sz]), q}, sizeof(t_s_fsp))))
	{
		((t_s_fsp*)tl->content)->last += TAS - 1;
		ft_bzero(ar[p->ar_sz], t_s_p * TAS);
		ft_memcpy(ar, p->ar, (sz = p->ar_sz++ * sizeof(t_s_p*)));
		ft_cleanfree(p->ar, sz);
		p->ar = ar;
		ft_lstadd(&p->nxt, tl);
		return (SUCCESS);
	}
	if (ar[p->ar_sz])
		free(ar[p->ar_sz]);
	if (ar)
		free(ar);
	return (SYS_ERR);
}

int						init_tssp(
	t_s_sp *p)
{
	int		r;

	r = SYS_ERR;
	p->ar_sz = 0;
	return (r = add_p_ar(p));
}

void					free_tssp(
	t_s_sp *points)
{
	t_s_p *const	lim = *points->ar + points->ar_sz;
	t_s_p			*p;

	p = *points->ar;
	while (p < lim)
		ft_cleanfree(p, TAG_AR_SZ * sizeof(t_s_p));
	ft_cleanfree(points->ar, sizeof(t_s_p*) * points->ar_sz);
}

int						get_nxt_p(
	t_s_s *scene,
	t_s_p **p_ret)
{
	t_s_sp *const	p = scene->points;
	t_s_fsp			*fp;

	*p_ret = 0;
	while (!(fp = (t_s_fsp*)p->nxt->content))
		if ((r = add_p_ar(p)) != SUCCESS)
			return (r);
	if ((*p_ret = fp->free++) == fp->last)
		ft_lstdelhead(&p->nxt);
	return (SUCCESS);
}
