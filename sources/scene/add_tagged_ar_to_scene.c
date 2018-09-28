#include "scene.h"

#define TPM DEF_TAG_POS_MASK
#define TPS DEF_TAG_POS_SHIFT
#define TAS DEF_TAG_AR_SZ

/*
**Add tagged array to scene.
** star: Scene Tagged ARay
*/
int					add_star(
	t_tar_adder f,
	size_t ar_sz,
	t_s_s *s)
{
	int		r;

	if ((r = (*f)(s)) == SUCCESS)
	{
		s->nxt_allocs++;
		s->ar_allocs += ar_sz;
	}
	return (r);
}

int					add_elements_tar(
	t_s_s *s,
	t_s_se *se)
{
	void			**ar;
	t_tag			last;
	t_list			*tl;
	size_t			sz;

	sz = se->e_sz * TAS;
	if ((ar = malloc((se->ar_sz + 1) * sizeof(void*))) &&
		(ar[se->ar_sz] = malloc(sz)) &&
		(last = (t_tag)p->ar_sz << TPS | TPM) &&
		(tl = ft_lstnew(&(t_s_ft){last & ~TPM, last}, FT_SZ)))
	{
		ft_bzero(ar[p->ar_sz], sz);
		ft_memcpy(ar, p->ar, (sz = p->ar_sz++ * sizeof(void*));
		ft_cleanfree(p->ar, sz);
		p->ar = ar;
		ft_lstadd(&p->nxt, tl);
		return (SUCCESS);
	}
	if (ar && ar[p->ar_sz])
		free(ar[p->ar_sz]);
	if (ar)
		free(ar);
	return (SYS_ERR);
}
