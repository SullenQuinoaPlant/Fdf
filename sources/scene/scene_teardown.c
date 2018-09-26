#include "scene.h"

void				scene_teardown(
	t_s_s **scene)
{
	free_tssp(&scene->points);
	free_tssd(&scene->dots);
	free_tssl(&scene->lines);
	free_tssa(&scene->areas);
	free_tsso(&scene->objects);
	ft_scleanfree(scene, sizeof(t_s_s));
}
