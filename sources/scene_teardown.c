#include "functions.h"
#include "scene.h"

/*
** - 'ct' ring ought to be completely freed after view ring free.
*/
void				scene_teardown(
	t_s_s **scene)
{
	t_s_s *const	s = *scene;

	if (!s)
		return ;
	disable_scene_looping(s);
	wait_scene_not_looping(s);
	free_tso_tsse_content(&s->e[e_o]);
	free_tsses(s);
	ring_free(sizeof(t_s_ao), ft_free, (void**)&s->ao);
	free_views(&s->v);
	ft_lstdel(&s->v_rel, ft_free);
	ft_scleanfree((void**)s, sizeof(t_s_s));
}
