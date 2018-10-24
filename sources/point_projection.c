#include "mlx.h"
#include "functions.h"
#include "scene.h"
#include "colors.h"

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
	v->e[e_p].prj_tick = v->ct->tick;
}

void						point_projection_iso_persist(
	t_s_sv *v,
	void *scene_point,
	t_s_pp const *const *points,
	void *view_point)
{
	t_s_pp *const	pp = (t_s_pp*)view_point;
	t_vpos			hw;

	point_projection(v, scene_point, points, view_point);
	if (iso_dbl_dims_to_tvpos(v, pp->xyz, hw) == SUCCESS)
		mlx_pixel_put(v->s->mlx, v->mlx_wdw, hw[V_W], hw[V_H], COL_WHITE); 
}
