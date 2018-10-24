#include "functions.h"
#include "scene.h"

void						scene_loop(
	t_s_s *s)
{
	t_e_seg	g;
	int		r;

	s->loop_status += LOOPING;
	g = e_p;
	r = SUCCESS;
	while (s->loop_status < LOOP_LOCK && g < e_seg_sz && r == SUCCESS)
	{
		scene_loop_free_views(s);
		r = scene_loop_refresh_views(s, &g);
	}
	if (s->loop_status < LOOP_LOCK && g == e_seg_sz && r == SUCCESS)
		tssv_proj_print(0, s->av);
		print_av_last(s->av);
	s->loop_status -= LOOPING;
}
