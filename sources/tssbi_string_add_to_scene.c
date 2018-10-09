#include "scene.h"

static int				no_scene_builder(
	t_s_sbi *a,
	t_s_s *b)
{
	(void)a;
	(void)b;
	return (SUCCESS);
}

static int				use_input(
	t_s_sbi *input,
	t_s_s *scene)
{
	t_scene_builder	f[e_sit_sz] = {
		no_scene_builder,
		cdgfxyrz_builder
	};

	return (f[input->type](input->input, scene));
}

int						add_tssbis_to_scene(
	t_s_sbi *input_str,
	t_s_s *scene)
{
	int		r;

	while (input_str)
		if ((r = use_input(input_str++, scene) != SUCCESS))
			break;
	return (r);
}
