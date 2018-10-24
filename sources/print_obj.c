#include "functions.h"
#include "scene.h"

int							print_obj_groups(
	t_e_seg const *print_order,
	int grp_ct,
	t_s_o *o,
	t_s_sv *v)
{
	int				i;
	t_e_seg			g;
	t_printer 		prt;
	t_list			*p;
	int				r;

	i = -1;
	while (++i < grp_ct)
	{
		g = print_order[i];
		if (!(prt = v->e[g].prt))
			continue ;
		p = o->e[g];
		while (p)
			if ((r = prt(v, *(t_tag*)p->content)) != SUCCESS)
				return (r);
			else
				p = p->next;
		v->e[g].prt_tick = v->e[e_p].prj_tick;
	}
	return (SUCCESS);
}

int							print_object(
	t_s_sv *v,
	t_tag t)
{
	t_s_op *const	op = &((t_s_op*)v->e[e_o].ar[t >> TPS])[t & TPM];
	t_s_o *const	o = &((t_s_o*)v->s->e[e_o].ar[t >> TPS])[t & TPM];
	uint8_t const	flgs = (o->flgs | op->set_flgs) & op->un_flgs;
	t_e_seg const	print_order[e_seg_sz - 1] = {
						e_o,
						e_f,
						e_l,
						e_a,
						e_d};
	int				r;

	r = SUCCESS;
	if (flgs & O_SHOW)
	{
		r = print_obj_groups(&print_order[0], e_seg_sz - 1, o, v);
	}
	return (r);
}
