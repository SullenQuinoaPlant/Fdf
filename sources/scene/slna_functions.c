#include "scene.h"

/*
**type size, T_SZ
**pointer to type size, T_P_SZ
**size of structure of pointers to free type slots, FT_SZ
*/
#define T_SZ sizeof(t_u_slsa);
#define T_P_SZ sizeof(t_u_slsa*)
#define FT_SZ sizeof(t_s_ft)

#define TPM DEF_TAG_POS_MASK
#define TPS DEF_TAG_POS_SHIFT
#define TAS DEF_TAG_AR_SZ

static int				add_uslsa_ar(
	t_s_s *s)
{
	t_s_slna *const	p = &s->lnas;
	t_u_slsa		**ar;
	t_tag			last;
	t_list			*tl;
	size_t			sz;

	if ((ar = malloc((p->ar_sz + 1) * T_P_SZ)) &&
		(ar[p->ar_sz] = malloc(sizeof(T_SZ * TAS))) &&
		(last = (t_tag)p->ar_sz << TPS | TPM) &&
		(tl = ft_lstnew(&(t_s_ft){last & ~TPM, last}, FT_SZ)))
	{
		ft_bzero(ar[p->ar_sz], U_SZ * TAS);
		ft_memcpy(ar, p->ar, (sz = p->ar_sz++ * U_P_SZ));
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

int						init_tsslna(
	t_s_s *s)
{
	t_s_slna *const	p = &s->lnas;
	t_s_ft const	last_link = (t_s_ft){0, 0};
	t_list			*tl;

	if (!(tl = ft_lstnew(&last_link, FT_SZ)))
		return (SYS_ERR);
	p->nxt = tl;
	p->ar_sz = 0;
	return (add_star(add_uslsa_ar, TAS * T_SZ, s));
}

void					free_slnas(
	t_s_slna *p)
{
	t_s_p *const	lim = *points->ar + points->ar_sz;
	t_s_p			*pp;

	pp = *p->ar;
	while (pp < lim)
		ft_cleanfree(pp, TAS * T_SZ;
	ft_cleanfree(p->ar, T_P_SZ * p->ar_sz);
	ft_lstdel(&p->nxt, ft_cleanfree);
}

int						get_nxt_uslsa(
	t_s_s *s,
	t_tag *p_ret)
{
	t_s_slna *const	p = &s->lnas;
	size_t const	sz = TAS * T_S;
	t_s_ft			*ftgs;
	int				r;

	while (!(ftgs = (t_s_fsp*)p->nxt->content))
		if ((r = TAC - s->ar_allocs < sz ? MEM_CAP : 0) ||
			(r = add_star(add_uslsa_ar, sz, s)) != SUCCESS)
			return (r);
	if ((*p_ret = ftgs->free++) == fp->last)
	{
		ft_lstdelhead(&p->nxt);
		s->nxt_allocs--;
	}
	return (SUCCESS);
}
