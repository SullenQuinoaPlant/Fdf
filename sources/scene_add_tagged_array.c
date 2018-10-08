#include "scene.h"

int							add_star(
	t_s_s *s,
	t_e_seg g)
{
	t_s_se *const	se = s->e[g];
	size_t const	sz = se->e_sz * TAS;
	t_list			*tl;

	if ((r = tssv_tar_allocs(map_seg_to_vpg(g), s)) == SUCCESS) &&
		(r = alloc_tar(s, &se->ar_sz, se->e_sz, &se->ar)) == SUCCESS &&
		(reg_freetags(((t_tag)se->ar_sz) << TPS, TPM, s, g)) == SUCCESS)
		return (SUCCESS);
	return (r);
}