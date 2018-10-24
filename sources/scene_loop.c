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
	while (g < e_seg_sz && s->loop_status < LOOP_LOCK)
	{
		scene_loop_free_views(
		scene_loop_update_views(s, &g);
	}
	s->loop_status -= LOOPING;
}
