#include "functions.h"
#include "scene.h"

/*
** - 'ct' ring ought to be completely freed after view ring free
*/
void				scene_teardown(
	t_s_s **s)
{
	t_s_s *const	scene = *s;
	t_e_seg			i;

	if (!scene)
		return ;
	disable_scene_loop(scene);
	wait_scene_not_looping(scene);
	free_tso_tsse_content(&scene->e[e_o]);
	i = e_p;
	while (i < e_seg_sz)
		free_tsse(&scene->e[i++], scene);
	ring_free(sizeof(t_s_ao), ft_free, (void**)&(**s).ao);
	free_views(&scene->v);
	ft_lstdel(&s->v_rel);
	ft_scleanfree((void**)s, sizeof(t_s_s));
}
