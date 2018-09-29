#include "scene.h"

void				scene_teardown(
	t_s_s **s)
{
	t_s_s *const	scene = *s;
	t_e_seg			i;

	if (!scene)
		return ;
	i = e_spnv;
	while (i < e_seg_sz)
		free_tsse(&scene->es[i])
	free_projs(scene->prjs)
	free_views(scene.views);
	ft_scleanfree(scene, sizeof(t_s_s));
}
