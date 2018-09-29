#include "scene.h"

int						pnvg_deep_copy(
	t_s_s *s,
	t_s_uspsv ***ret)
{
	t_s_se *const	p = &s->se[e_pnvg];
	size_t const	subsz = TAS * sizeof(t_u_spsv);
	size_t const	sz = subsz * p->ar_sz;
	size_t			i;
	t_s_uspsv (*	p_ret)[TAS];

	if (TAC - s->ar_allocs < sz)
		return (MEM_CAP);
	if (!(*ret = malloc(sz)))
		return (SYS_ERR);
	p_ret = (t_s_uspsv(*)[TAS])ret;
	i = -1;
	while (++i < p->ar_sz)
		ft_memcpy(&p_ret[i][0], p->ar[i], subsz);
	return (SUCCESS);
}
