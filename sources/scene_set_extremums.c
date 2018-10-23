#include "scene.h"

void						scene_set_extr(
	t_s_s *s)
{
	minmax_permute(s->minmax, s->extr);
	barycenter(s->extr, MMXYZPC, s->extr_bar);
}
