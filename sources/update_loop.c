#include "scene.h"

int							ring_update_a_view_prjs(
	void *p_teseg,
	t_ring p_view)
{
	t_s_sv *const	v = (t_s_sv*)p_view;
	t_e_seg *const	pg = (t_e_seg*)p_teseg;
	t_ticker const	master = v->e[e_p].prj_tick;
	t_e_seg			g;

	g = e_p;
	if (v->ct->tick != master)
	{
		tssv_grp_apply_proj(v, &v->s[g], &v->e[g]);
		tssv_grp_apply_proj(v, &v->s[e_o], &v->e[e_o]);
	}
	else
	{
		if (v->e[e_d].prj_tick != master)
			set_v_background(v);
		while (++g <= *pg)
			if (v->e[g].prj_tick != 
	}
	*pg = g;
	return (RING_SUCCESS);
}
	
void						update_loop(
	t_s_s *s)
{
	t_s_sv	*v;
	t_e_seg	g;
	int		no_work;

	if (++s->is_updating > 1)
		return ;
	no_work = 0;
	g = e_p;

	s->is_updating = 0;
}
