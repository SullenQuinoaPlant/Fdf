#include "scene.h"

static int					downstream_allocs(
	t_s_s *s,
	t_e_seg g)
{
	int		r;

	if (g == e_spnv)
		r = tspc_tar_alloc(s);
	else
		r = tssv_alloc(s, g);
	return (r);
}

int							add_star(
	t_s_s *s,
	t_e_seg g)
{
	t_s_se *const	se = s->es[g];
	size_t const	sz = se->e_sz * TAS;
	void			**ar;
	t_list			*tl;

	if ((r = downstream_allocs(s, g, se->ar_sz + 1)) == SUCCESS &&
		(r = alloc_tar(s, &se->ar_sz, se->e_sz, &se->ar)) == SUCCESS &&
		(reg_freetags((t_tag)se->ar_sz << TPS, TPM, s, p)) == SUCCESS)
		return (SUCCESS);
	return (r);
}
