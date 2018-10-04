#include "scene.h"

static void				init_vars(
	t_s_s *s)
{
	s->ar_allocs = 0;
	s->nxt_allocs = 0;
	ft_bzero(s->e, sizeof(s->es));
	s->ao = 0;
	s->ct = 0;
	s->v = 0;
}

static int				init_scene(
	t_s_s **p_ret_scene)
{
	t_s_s	*s;
	t_e_seg	i;
	int		r;

	*p_ret_scene = 0;
	if (!(scene = malloc(sizeof(t_s_s))))
		return (SYS_ERR);
	init_vars(s);
	i = e_spnv;
	while (i < e_seg_sz && (r = init_tsse(&s->e[i])) == SUCCESS))
		i++;
	if (r != SUCCESS)
		scene_teardown(&scene);
	else
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