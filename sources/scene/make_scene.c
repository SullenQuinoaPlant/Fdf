#include "scene.h"

static int				init_vars(
	t_s_s *s)
{
	s->ar_allocs = 0;
	s->nxt_allocs = 0;
	s->nullproj = (t_s_prj){0, 0, 0, 0, 0, 0};
	s->views = 0;
	return (SUCCESS);
}

static int				init_scene(
	t_s_s **p_ret_scene)
{
	int		r;
	t_s_s	*scene;

	r = SYS_ERR;
	*p_ret_scene = 0;
	if (!(scene = malloc(sizeof(t_s_s))) ||
		(r = init_vars(scene) != SUCCESS) ||
		(r = init_tssp(&scene->points)) != SUCCESS ||
		(r = init_tssd(&scene->dots)) != SUCCESS ||
		(r = init_tssl(&scene->lines)) != SUCCESS ||
		(r = init_tssa(&scene->areas)) != SUCCESS ||
		(r = init_tsso(&scene->objects)) != SUCCESS)
		scene_teardown(&scene);
	*p_ret_scene = scene;
	return (r);
}

int						make_scene(
	t_s_sbi *input_str,
	t_s_s **p_ret_scene)
{
	t_s_s	*scene;
	int		r;

	if (!p_ret_scene)
		return (BAD_ARGS);
	if ((r = init_scene(p_ret_scene)) == SUCCESS && input_str)
		r = add_tssbis_to_scene(input_str, *p_ret_scene);
	free_tssbi_str(input_str);
	return (r);
}
