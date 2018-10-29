#include "functions.h"
#include <math.h>
#include "scene.h"

static void				set_zoom_effect(
	t_xyz extr[MMXYZPC],
	t_s_sv *v)
{
	t_xyz	mm[MIN_MAX_SZ];
	double	hw[VIEW_DIMS];
	double	d1;
	double	d2;
	int		i;

	minmax_set(extr, MMXYZPC, mm);
	cam_tr((t_xyz){0, 0, mm[MIN][Z]}, v);
	i = -1;
	while (++i < VIEW_DIMS)
	{
		d1 = fabs(mm[MAX][i]);
		d2 = fabs(mm[MIN][i]);
		hw[i] = (2.0 * fmax(d1, d2)) / (double)(i == V_W ? v->w : v->h);
	}
	cam_zoom(fmin(hw[V_H], hw[V_W]), v);
}

int						add_default_iso_v(
	t_s_sv **ret_v,
	t_s_s *s)
{
	t_s_sv	*v;
	t_xyz	extr_bar;
	t_xyz	extr[MMXYZPC];
	int		i;
	int		r;

	ret_v ? (*ret_v = 0) : ((t_s_sv*)0);
	if ((r = add_isometric_v(s->v_hw_def, (t_zntr){1, 0, 0, 0}, &v, s)))
		return (r);
	tpctrm_apply(v->ct->mashed, s->extr_bar, extr_bar);
	cam_tr(extr_bar, v);
	i = -1;
	while (++i < MMXYZPC)
		tpctrm_apply(v->ct->mashed, s->extr[i], extr[i]);
	set_zoom_effect(extr, v);
	ret_v ? (*ret_v = v) : ((t_s_sv*)0);
	return (SUCCESS);
}
