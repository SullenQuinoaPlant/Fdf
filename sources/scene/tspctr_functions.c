#include "scene.h"

void						onelessview(
	t_s_pctr *ct)
{
	if (!(ct->view_ct -= 1))
		return ;
	if (prv)
		onelessview(prv);
	ring_shrink(sizeof(t_s_pctr), 0, &ct);
}
