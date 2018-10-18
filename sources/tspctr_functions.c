#include "scene.h"

void						tspctr_onelessview(
	t_s_pctr *ct)
{
	if (!ct)
		return ;
	if (ct->nxt && ct->nxt->refs == 1)
		ct->nxt = (t_s_pctr*)ct->nxt->ring.nxt;
	onelessview(ct->prv);
	if (!(--ct->refs))
		ring_shrink(sizeof(t_s_pctr), 0, (void**)&ct);
}
