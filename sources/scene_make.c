#include "functions.h"
#include "scene.h"

static void				init_vars(
	t_s_s *s)
{
	ft_bzero(s, sizeof(t_s_s));
	scene_init_extr(s);
	ft_memcpy(s->v_hw_def, (t_vpos){DEF_V_H, DEF_V_W}, sizeof(t_vpos));
}

static int				init_scene(
	t_s_s **p_ret_scene)
{
	t_s_s	*s;
	t_e_seg	i;
	int		r;

	*p_ret_scene = 0;
	if (!(s = malloc(sizeof(t_s_s))))
		return (SYS_ERR);
	init_vars(s);
	i = e_p;
	while (i < e_seg_sz && (r = init_tsse(i, &s->e[i], s)) == SUCCESS)
		i++;
	if (r != SUCCESS)
		scene_teardown(&s);
	else
		*p_ret_scene = s;
	return (r);
}

int						make_scene(
	t_s_sbi **input_str,
	t_s_s **p_ret_scene)
{
	int		r;

	if (!p_ret_scene)
		return (BAD_ARGS);
	if ((r = init_scene(p_ret_scene)) == SUCCESS && input_str)
		r = add_tssbis_to_scene(input_str, *p_ret_scene);
	free_tssbi_str(input_str);
	return (r);
}
