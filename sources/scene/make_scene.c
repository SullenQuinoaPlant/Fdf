#include "scene.h"

static int				init_scene(
	t_s_s **p_ret_scene)
{
	if (!(*p_ret_scene = malloc(sizeof(t_s_s))))
		return (SYS_ERR);
	(*p_ret_scene)->points = (t_s_sp){0, 0};
	(*p_ret_scene)->dots = (t_s_sd){0, 0};
	(*p_ret_scene)->lines = (t_s_sl){0, 0};
	return (SUCCESS);
}

int						make_scene(
	t_s_sbi **input_str,
	t_s_s **p_ret_scene)
{
	t_s_s	*scene;
	int		r;

	if (!p_ret_scene)
		return (BAD_ARGS);
	if ((r = init_scene(p_ret_scene)) != SUCCESS)
		return (r);
	if (input_str)
		r = add_tssbis_to_scene(input_str, *p_ret_scene);
	return (r);
}
