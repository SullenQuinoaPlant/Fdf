#include "mlx.h"
#include "functions.h"
#include "scene.h"

static int				init_mlx(
	void **ret)
{
	if (*ret = mlx_init())
		return (SUCCESS);
	return (SYS_ERR);
}

static void				init_vars(
	t_s_s *s)
{
	ft_bzero(s, sizeof(t_s_s));
	disable_scene_looping(s);
	minmax_init(s->minmax);
	ft_memcpy(s->v_hw_def, (t_vpos){DEF_V_H, DEF_V_W}, sizeof(t_vpos));
}


static int				init_scene(
	t_s_s **p_ret_scene)
{
	t_s_s	*s;
	void	*mlx;
	int		r;

	*p_ret_scene = 0;
	if ((s = malloc(sizeof(t_s_s))) &&
		(mlx
		(r = init_tsses(s)) == SUCCESS) &&

		return (SYS_ERR);
	init_vars(s);
	if (r != SUCCESS)
		scene_teardown(&s);
	else
		*p_ret_scene = s;
	return (r);
}

int						make_scene(
	t_s_sbi **in,
	t_s_s **ret)
{
	void	*mlx;
	t_s_s	*s;
	int		r;

	if (!p_ret_scene)
		return (BAD_ARGS);
	*ret = 0;
	if ((r = init_mlx(&mlx) == SUCCESS) &&
		(r = init_scene(&s)) == SUCCESS &&
		(!in || (r = add_tssbis_to_scene(in, *p_ret_scene)) == SUCCESS))
		enable_scene_looping((*ret = s));
	else if (mlx)
		scene_teardown(s);
	free_tssbi_str(input_str);
	return (r);
}
