#include "functions.h"
#include "scene.h"

void						point_projection(
	t_s_sv *v,
	void *scene_point,
	t_s_pp const *const *points,
	void *view_point)
{
	t_s_p *const	p = (t_s_p*)scene_point;
	t_s_pp *const	pp = (t_s_pp*)view_point;

	(void)points;
	tpctrm_apply(v->ct->mashed, p->xyz, pp->xyz);
	txyz_to_ttpr(pp->xyz, pp->tpr);
	v->e_tick[e_p] = v->ct->tick;
}
