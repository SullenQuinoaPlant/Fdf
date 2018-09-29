#include "scene.h"

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
