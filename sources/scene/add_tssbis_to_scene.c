#include "scene.h"

static int				use_input(
	t_s_sbi *input,
	t_s_s *scene)
{
	t_scene_builder	f[e_sit_sz] = {
		scene_builder_empty,
		scene_builder_cpgfxyrz
	};
	int		r;

	r = f[input->type](input->input, scene);
	return (r);
}

static void				free_input(
	t_s_sbi **input)
{
	t_tssbi_freer	f[e_sit_sz] = {
		0,
		free_tscpgfxyrz
	};

	r = f[input->type](input);
	return (r);
}

static void				free_input_str(
	t_s_sbi **input_str,
	t_s_sbi *p_strend,
{
	size_t	sz;

	sz = (++p_strend - *input_str);
	ft_scleanfree(input_str, sz);
}

int						add_tssbis_to_scene(
	t_s_sbi **input_str,
	t_s_s *scene)
{
	t_s_sbi	*p;
	int		r;

	p = *input_str;
	r = SUCCESS;
	while (p && r == SUCCESS)
	{
		r = r == SUCCESS ? use_input(p, scene) : r;
		free_input(p++);
	}
	while (p)
		free_input(p++);
	free_input_str(input_str, p);
	return (r);
}
