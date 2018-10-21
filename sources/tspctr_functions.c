#include "scene.h"

void						tspctr_onelessview(
	t_s_pctr *ct)
{
	if (!ct)
		return ;
	if (ct->nxt && ct->nxt->refs == 1)
		ct->nxt = (t_s_pctr*)ct->nxt->ring.nxt;
	tspctr_onelessview(ct->prv);
	if (!(--ct->refs))
		ring_shrink(sizeof(t_s_pctr), ft_free, (void**)&ct);
}

/*
**This shouldn't be needed:
**void						tspctr_ring_free(
**	void *free_this,
**	size_t unused)
**{
**	(void)unused;
**	t_s_pctr *const	p = (t_s_pctr*)free_this;
**
**	if (p->nxt)
**		ring_free(sizeof(t_s_pctr), tspctr_ring_free, (void**)&p->nxt);
**	free(p);
**}
*/
