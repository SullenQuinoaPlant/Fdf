#include "scene.h"

static int			add_actually(
	size_t sz,
	t_s_s *s,
	t_s_se *p)
{
	void			**ar;
	t_list			*tl;

	if ((ar = malloc((p->ar_sz + 1) * sizeof(void*))) &&
		(ar[p->ar_sz] = malloc(sz)) &&
		(tl = ft_lstnew(&(t_s_ft){(t_tag)p->ar_sz << TPS, TPM}, FT_SZ)))
	{
		((t_s_ft*)tl->content)->last |= ((t_s_ft*)tl->content)->first;
		ft_lstadd(&p->nxt, tl);
		ft_bzero(ar[p->ar_sz], sz);
		ft_memcpy(ar, p->ar, (sz = p->ar_sz++ * sizeof(void*));
		ft_cleanfree(p->ar, sz);
		p->ar = ar;
		return (SUCCESS);
	}
	if (ar && ar[p->ar_sz])
		free(ar[p->ar_sz]);
	if (ar)
		free(ar);
	return (SYS_ERR);
}

/*
** tar: Tagged ARay
*/
int					add_tar(
	t_s_se *se,
	t_s_s *s)
{
	size_t const	sz = se->e_sz * TAS;
	int				r;

	if (!(r = TAC - s->ar_allocs < sz ? MEM_CAP : 0) &&
		((r = (*f)(sz, s, se)) == SUCCESS)
	{
		s->nxt_allocs++;
		s->ar_allocs += sz;
	}
	return (r);
}
