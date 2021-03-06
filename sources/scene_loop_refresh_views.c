#include "functions.h"
#include "scene.h"

static void					refresh_pt_obj_proj(
	t_s_sv *v)
{
	tssv_grp_apply_proj(v, &v->s->e[e_p], &v->e[e_p]);
	tssv_grp_apply_proj(v, &v->s->e[e_o], &v->e[e_o]);
}

static void					refresh_a_grp(
	t_s_sv *v,
	t_e_seg g)
{
	tssv_grp_apply_proj(v, &v->s->e[g], &v->e[g]);
	print_active_objects_a_grp(v, g);
	tssv_push_to_displays(v);
}

static int					ring_refresh_a_view(
	void *p_teseg,
	t_ring p_view)
{
	t_s_sv *const	v = (t_s_sv*)p_view;
	t_s_s *const	s = v->s;
	t_e_seg *const	pg = (t_e_seg*)p_teseg;
	t_e_seg			g;
	t_ticker		master;

	if (v == s->av)
		return (RING_SUCCESS);
	g = e_p;
	while (s->loop_status < LOOP_LOCK && g <= *pg)
	{
		if (g == e_p && (master = v->ct->tick) != v->e[e_p].prj_tick)
			refresh_pt_obj_proj(v);
		else if (v->e[g].prj_tick != master)
		{
			if (g == e_d)
				tssv_reset_print_canvas(v);
			refresh_a_grp(v, g);
			break ;
		}
		g++;
	}
	*pg = g;
	return (s->loop_status >= LOOP_LOCK ? RING_STOP : RING_SUCCESS);
}

int							scene_loop_refresh_views(
	t_s_s *s,
	t_e_seg *g)
{
	t_s_sv *const	av = s->av;
	t_s_ve *const	priority = &av->e[e_p];
	int				r;

	if (priority->prj_tick != av->ct->tick)
	{
		tssv_grp_apply_proj(av, &s->e[e_p], priority);
		*g = e_p;
		r = SUCCESS;
	}
	else
	{
		r = ring_apply(av->ring.nxt, ring_refresh_a_view, g);
		r = r == RING_SYS_ERR ? SYS_ERR : SUCCESS;
	}
	return (r);
}
