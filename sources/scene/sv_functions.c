#include "scene.h"

static int				init_view(
	t_s_s *s,
	t_s_v *v)
{
	int		r;

	ft_bzero(v, sizeof(t_s_v));

}

int						new_view(
	t_s_s *s,
	t_viewbuilder f,
	t_s_v **ret)
{
	t_s_v	*v;
	int		r;

	ret = 0;
	r = SYS_ERR;
	if (ring_expand(sizeof(t_s_v), 0, &s->views) == RING_SUCCESS ||
		(r = init_view(s, v)) == SUCCESS ||
		(r = (*f)(s, v)) == SUCCESS ||
		(r = add_view_to_scene(v, s)) == SUCCESS)
		*ret = v;
	return (r);
}
