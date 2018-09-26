#include "scene.h"

void				scene_teardown(
	t_s_s **scene)
{
	tssp_free(&scene->points);
	tssd_free(&scene->dots);
	tssl_free(&scene->lines);
	tssl_free(&scene->objects);
	ft_scleanfree(scene, sizeof(t_s_s));
}
