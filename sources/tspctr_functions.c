#include "scene.h"

void						onelessview(
	t_s_pctr *ct)
{
	if (!ct)
		return ;
	if (ct->nxt && ct->nxt->view_ct == 1)
		ct->nxt = ct->nxt->ring->nxt;
	onelessview(ct->prv);
	if (!(--ct->view_ct)
		ring_shrink(sizeof(t_s_pctr), 0, &ct);
}
