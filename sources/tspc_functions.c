#include "scene.h"

static int					tspc_add_tar(
	void *p_s,
	t_ring p_tspc)
{
	t_s_s *const	s = (t_s_s*)p_s;
	t_s_pc *const	pc = (t_s_pc*)p_tspc;
	t_s_ta *const	ta = &pc->coords
	int		r;

	if ((r = alloc_tar(s, sizeof(t_s_p), &ta->ar_sz, &ta->ar)) == SUCCESS)
		r = ring_apply(pc->nxt, tspc_add_tar, p_s);
	else
		r = RING_SYS_ERR;
	return (r)
}
	
int							tspcs_tar_alloc(
	t_s_s *s)
{
	int		r;

	r = ring_apply(&s->canonical, tspc_add_tar, s);
	r = r == RING_SUCCESS ? SUCCESS : SYS_ERR;
	return (r);
}
