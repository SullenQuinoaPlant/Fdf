#include "scene.h"

static int				init_scene(
	t_s_s **p_ret_scene)
{
	int		r;
	t_s_s	*scene;

	r = SYS_ERR;
	*p_ret_scene = 0;
	if (!(scene = malloc(sizeof(t_s_s))) ||
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
	r = SYS_ERR;
	if ((r = init_scene(p_ret_scene)) != SUCCESS &&_input_str)
		free_tssbis(input_str);
	else if (input_str)
		r = add_tssbis_to_scene(input_str, *p_ret_scene);
	return (r);
}
