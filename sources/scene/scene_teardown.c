#include "scene.h"

void				scene_teardown(
	t_s_s **scene)
{
	free_spnv(&scene->pnvs);
	free_slna(&scene->lnas);
	ft_scleanfree(scene, sizeof(t_s_s));
}
