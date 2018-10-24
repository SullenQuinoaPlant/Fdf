#include "functions.h"
#include "scene.h"

void						tssv_proj_print(
	int proj_points,
	t_s_sv *v)
{
	t_s_s *const	s = v->s;
	t_e_seg const	order[e_seg_sz - 1] = {e_p, e_o, e_d, e_l, e_a, e_f};
	int				i;
	t_e_seg			g;

	i = proj_points ? -1 : 0;
	while (++i < e_seg_sz)
	{
		g = order[i];
		tssv_grp_apply_proj(av, &s->e[g], &v->e[g]);
		print_active_objects_a_grp(v, g);
	}
}
