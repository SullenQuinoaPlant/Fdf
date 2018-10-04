#include "scene.h"

static void			free_ct_ring(
	t_s_pctr **ring)
{
	ring_free(sizeof(t_s_pctr), 0, ring);
}

void				scene_teardown(
	t_s_s **s)
{
	t_s_s *const	scene = *s;
	t_e_eg			i;

	if (!scene)
		return ;
	i = e_spnv;
	while (i < e_seg_sz)
		free_tsse(&scene->e[i])
	free_ct_ring(&scene->ct);
	free_views(scene.views);
	ft_scleanfree(scene, sizeof(t_s_s));
}
