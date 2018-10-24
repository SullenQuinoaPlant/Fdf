#include "functions.h"
#include "scene.h"

void						print_active_objects_a_grp(
	t_s_sv *v,
	t_e_seg g)
{
	t_s_ao *const	lim = v->ao;
	t_e_seg const	group[1] = {g};
	t_s_o			*o;
	t_s_ao			*p;

	p = lim;
	while (1)
	{
		o = (t_s_o*)get_se_tag(v->s, g, p->tag);
		print_obj_groups(group, 1, o, v);
		if ((p = (t_s_ao*)p->ring.nxt) == lim)
			break ;
	}
}

void						print_active_objects(
	t_s_sv *v)
{
	t_s_ao *const	lim = v->ao;
	t_s_ao			*p;

	p = lim;
	while (1)
	{
		print_object(v, p->tag);
		if ((p = (t_s_ao*)p->ring.nxt) == lim)
			break ;
	}
}
