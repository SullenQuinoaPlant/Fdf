#include "scene.h"

void						disable_scene_loop(
	t_s_s *s)
{
	s->loop_status += LOOP_LOCK;
	return ;
}

void						enable_refresh(
	t_s_s *s)
{
	while (s->loop_status >= LOOP_LOCK)
		s->loop_status -= LOOP_LOCK;
	return ;
}
