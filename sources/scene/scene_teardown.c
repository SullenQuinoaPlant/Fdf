#include "scene.h"

void				scene_teardown(
	t_s_s **s)
{
	t_s_s *const scene = *s;

	if (!scene)
		return ;
	free_spnv(&scene->pnvs);
	free_slna(&scene->lnas);
	free_sobjs(&scene->os);
	free_views(scene.views);
	ft_scleanfree(scene, sizeof(t_s_s));
}
