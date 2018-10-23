#include "functions.h"
#include "scene.h"

static void				set_zoom_ratio(
	t_extr extr[MMXYZPC],
	t_s_sv *v)
{
}

static void				set_translation(
	t_extr extr_bar,
	t_s_pctr *ct)
{
	:vs
}

int						add_default_iso_v(
	t_s_sv **ret_v,
	t_s_s *s)
{
	t_s_sv	*v;
	t_xyz	extr[MMXYZPC];
	t_xyz	extr_bar;
	int		i;
	int		r;

	ret_v ? (*ret_v = 0) : (1);
	if ((r = add_isometric_v(s->v_hw_def, (t_zntr){1, 0, 0, 0}, &v, s)))
		return (r);
	tpctrm_apply(v->ct, s->extr_bar, extr_bar);
	set_translation(extr_bar, extr, v->ct);
	i = -1;
	while (++i < MMXYZPC)
		tpctrm_apply(v->ct, s->extr[i], extr[i]);
	set_zoom_ratio(extr, v);
}
