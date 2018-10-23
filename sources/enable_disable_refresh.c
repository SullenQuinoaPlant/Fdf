#include "scene.h"

void						disable_refresh(
	t_s_s *s)
{
	s->refreshing += REFRESH_LOCK;
	return ;
}

void						enable_refresh(
	t_s_s *s)
{
	while (s->refreshing >= REFRESH_LOCK)
		s->refreshing -= REFRESH_LOCK;
	return ;
}
