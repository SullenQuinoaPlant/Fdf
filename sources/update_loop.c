#include "scene.h"

static void					update_pt_obj_proj(
	t_s_sv *v)
{
	tssv_grp_apply_proj(v, &v->s[g], &v->e[g]);
	tssv_grp_apply_proj(v, &v->s[e_o], &v->e[e_o]);
}

static void					update_a_grp(
	t_s_sv *v,
	t_e_seg g)
{
	tssv_grp_apply_proj(v, &v->s[g], &v->e[g]);
	print_active_objects_a_grp(v, g);
	tssv_push_to_displays(v);
}

static int					ring_update_a_view(
	void *p_teseg,
	t_ring p_view)
{
	t_s_sv *const	v = (t_s_sv*)p_view;
	t_e_seg *const	pg = (t_e_seg*)p_teseg;
	t_ticker const	master = v->e[e_p].prj_tick;
	t_e_seg			g;

	g = e_p;
	if (v->ct->tick != master)
		update_pt_obj_proj(v);
	else
	{
		if (v->e[e_d].prj_tick != master)
			tssv_reset_print_canvas(v);
		while (++g <= *pg)
			if (v->e[g].prj_tick != master)
			{
				update_a_grp(v, g);
				break ;
			}
	}
	*pg = g;
	return (RING_SUCCESS);
}
	
void						refresh_loop(
	t_s_s *s)
{
	t_s_sv	*v;
	t_e_seg	g;

	s->refreshing += REFRESHING;
	g = e_p;
	while (g < e_seg_sz && s->refreshing < REFRESH_LOCK)
	{
		r = ring_apply((void*)s->ao, ring_update_a_view, &g);
		if (r != RING_SUCCESS)
			break ;
	}
	s->is_updating -= REFRESHING;
}
