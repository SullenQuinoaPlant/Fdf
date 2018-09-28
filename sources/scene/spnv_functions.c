#include "scene.h"

/*
**type size, T_SZ
**pointer to type size, T_P_SZ
**size of structure of pointers to free type slots, FT_SZ
*/
#define T_SZ sizeof(t_u_spsv);
#define T_P_SZ sizeof(t_u_spsv*)
#define FT_SZ sizeof(t_s_ft)

#define TPM USPSV_TAG_POS_MASK
#define TPS USPSV_TAG_POS_SHIFT
#define TAS USPSV_TAG_AR_SZ

#define AR_SZ (TAS * T_SZ)

static int				add_uspsv_ar(
	t_s_s *s)
{
	t_s_spnv *const	p = &s->pnvs;
	t_u_spsv		**ar;
	t_tag			last;
	t_list			*tl;
	size_t			sz;

	if ((ar = malloc((p->ar_sz + 1) * T_P_SZ)) &&
		(ar[p->ar_sz] = malloc(sizeof(T_SZ * TAS))) &&
		(last = (t_tag)p->ar_sz << TPS | TPM) &&
		(tl = ft_lstnew(&(t_s_ft){last & ~TPM, last}, FT_SZ)))
	{
		ft_bzero(ar[p->ar_sz], T_SZ * TAS);
		ft_memcpy(ar, p->ar, (sz = p->ar_sz++ * T_P_SZ));
		ft_cleanfree(p->ar, sz);
		p->ar = ar;
		ft_lstadd(&p->nxt, tl);
		s->nullproj.tr_res = ar;
		return (SUCCESS);
	}
	if (ar && ar[p->ar_sz])
		free(ar[p->ar_sz]);
	if (ar)
		free(ar);
	return (SYS_ERR);
}

int						init_tsspnv(
	t_s_s *s)
{
	t_s_spnv *const	p = &s->pnvs;
	t_s_ft const	last_link = (t_s_ft){0, 0};
	t_list			*tl;
	int				r;

	if (!(tl = ft_lstnew(&last_link, FT_SZ)))
		return (SYS_ERR);
	p->nxt = tl;
	p->ar_sz = 0;
	return (add_star(add_uspsv_ar, AR_SZ, s));
}

void					free_spnvs(
	t_s_spnv *p)
{
	t_s_p *const	lim = *points->ar + points->ar_sz;
	t_s_p			*pp;

	pp = *p->ar;
	while (pp < lim)
		ft_cleanfree(pp, AR_SZ;
	ft_cleanfree(p->ar, T_P_SZ * p->ar_sz);
	ft_lstdel(&p->nxt, ft_cleanfree);
}

int						get_nxt_uspsv(
	t_s_s *s,
	t_tag *p_ret)
{
	t_s_spnv *const	p = s->points;
	size_t const	sz = TAS * T_S;
	t_s_ft			*ftgs;
	int				r;

	while (!(ftgs = (t_s_fsp*)p->nxt->content))
		if ((r = TAC - s->ar_allocs < sz ? MEM_CAP : 0) ||
			(r = add_star(add_uspsv_ar, sz, s)) != SUCCESS)
			return (r);
	if ((*p_ret = ftgs->free++) == fp->last)
	{
		ft_lstdelhead(&p->nxt);
		s->nxt_allocs--;
	}
	return (SUCCESS);
}

int						chg_uspsv_ref(
	t_tag tag,
	int chg,
	t_s_s *s)
{
	int		r;
	int		*refs;

	refs = &(s->pnvs.ar[tag >> TPS])[tag & TPM].refs;
	if (chg > 0 && UINT_MAX - *refs <= (unsigned int)chg)
		return (REF_COUNT_TOO_BIG);
	else if (chg < 0 && *refs < (unsigned int)(-chg))
		return (NEGATIVE_REF_COUNT);
	*refs += chg;
	return (SUCCESS);
}

int						pnv_deep_copy(
	t_s_s *s,
	t_s_uspsv ***ret)
{
	t_s_spnv *const	p = s->pnvs;
	size_t			sz;
	size_t			i;
	t_s_uspsv (*	p_ret)[TAS];

	sz = p->ar_sz * AR_SZ;
	if (TAC - s->ar_allocs < sz)
		return (MEM_CAP);
	if (!(*ret = malloc(sz)))
		return (SYS_ERR);
	p_ret = (t_s_uspsv(*)[TAS])ret;
	i = -1;
	while (++i < p->ar_sz)
		ft_memcpy(&p_ret[i], p->ar[i], AR_SZ);
	return (SUCCESS);
}
