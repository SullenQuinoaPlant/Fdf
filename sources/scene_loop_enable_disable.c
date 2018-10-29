#include "scene.h"

void						disable_scene_looping(
	t_s_s *s)
{
	s->loop_status += LOOP_LOCK;
	return ;
}

void						enable_scene_looping(
	t_s_s *s)
{
	while (s->loop_status >= LOOP_LOCK)
		s->loop_status -= LOOP_LOCK;
	return ;
}

/*
**sleep not available, so it's an ugly tight loop.
*/

int							wait_scene_not_looping(
	t_s_s *s)
{
	char	status;

	while ((status = s->loop_status) && status > LOOP_LOCK)
		;
	return (SUCCESS);
}
