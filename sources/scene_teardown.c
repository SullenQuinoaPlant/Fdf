#include "functions.h"

void				scene_teardown(
	t_s_s **s)
{
	t_s_s *const	scene = *s;
	t_e_seg			i;

	if (!scene)
		return ;
	i = e_spnv;
	while (i < e_seg_sz)
		free_tsse(&scene->e[i]);
	free_views(scene->v);
	ft_scleanfree((void**)s, sizeof(t_s_s));
}
