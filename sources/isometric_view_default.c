#include "functions.h"
#include "scene.h"

static void				set_zoom_ratio(
	t_s_s *s,
	t_xyz extr[MMXYZPC],
	t_s_sv *v)
{
	t_xyz	extr[MMXYZPC];
	t_xyz	mm[MIN_MAX_SZ];
	int		i;

	i = -1;
	while (++i < MMXYZPC)
		tpctrm_apply(v->ct, s->extr[i], extr[i]);
	minmax_set(ext, MMXYZPC, mm);
}

int						add_default_iso_v(
	t_s_sv **ret_v,
	t_s_s *s)
{
	t_s_sv	*v;
	t_xyz	extr_bar;
	int		r;

	ret_v ? (*ret_v = 0) : (1);
	if ((r = add_isometric_v(s->v_hw_def, (t_zntr){1, 0, 0, 0}, &v, s)))
		return (r);
	tpctrm_apply(v->ct, s->extr_bar, extr_bar);
	cam_tr(v, extr_bar);
	set_zoom_ratio(extr, v);
}
