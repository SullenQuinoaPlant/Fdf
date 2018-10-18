#include "functions.h"
#include "scene.h"

void				scene_teardown(
	t_s_s **s)
{
	t_s_s *const	scene = *s;
	t_e_seg			i;

	if (!scene)
		return ;
	free_tso_tsse_content(&s->e[e_o]);
	i = e_p;
	while (i < e_seg_sz)
		free_tsse(&scene->e[i++]);
	free_views(scene->v);
	ft_scleanfree((void**)s, sizeof(t_s_s));
}
