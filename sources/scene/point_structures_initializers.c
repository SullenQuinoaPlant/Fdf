#include "scene.h"

void					init_tsp_ar(
	t_s_p *ar)
{
	size_t	i;

	i = -1;
	while (++i < TAG_AR_SZ)
		ar[i] = (t_s_p){{0, 0, 0}, {0, 0, 0}, 0, i};
}

int						add_p_ar(
	t_s_sp *p)
{
	t_s_p	**ar;
	t_s_fsp	*fsp;
	size_t	sz;

	if ((ar = malloc((p->ar_sz + 1) * sizeof(t_s_p*))) &&
		(ar[p->ar_sz] = malloc(sizeof(t_s_p * TAS))) &&
		)
	{
		ft_bzero(ar[p->ar_sz], t_s_p * TAS);
		ft_memcpy(ar, p->ar, (sz = p->ar_sz++ * sizeof(t_s_p*)));
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

int						init_tssp(
	t_s_sp *p)
{
	int		r;

	r = SYS_ERR;
	p->ars = 0;
	if ((p->ars = malloc(sizeof(t_s_p*))) &&
		(*p->ars = malloc(sizeof(t_s_p * TAG_AR_SZ)) &&
		(r = init_tsp_ar(*p->ars) == SUCCESS)
	{
		*p = (t_s_sp){p->ars, 1, (t_tag)0};
		init_tsp_ar(*p->ars);
	}
	else if (p->ars)
	{
		free(*p->ars);
		free(p->ars);
	}
}

int						get_nxt_p(
	t_s_s *scene,
	t_s_p **p_ret;
{
	t_s_sp *const	p = scene->points;
	t_s_fsp			*fp;

	r = SUCCESS;
	*p_ret = 0;
	while (!(fp = (t_s_fsp*)p->nxt->content) &&
		r == SUCCESS)
		r = add_p_ar(p);
	if (r == SUCCESS)
	{
		*p_ret = fp->free++;
		if (!(--fp->count))
			ft_lstdelhead(&p->nxt);
	}
	return (r);
}
