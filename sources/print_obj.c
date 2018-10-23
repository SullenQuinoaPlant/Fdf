#include "functions.h"
#include "scene.h"

int							print_obj_groups(
	t_e_seg *grps,
	int grp_ct,
	t_s_o *o,
	t_s_sv *v)
{
	t_printer 		prt;
	int				i;
	t_list			*p;
	int				r;

	i = -1;
	while (++i < e_seg_sz)
	{
		if (!(prt = v->e[print_order[i]].prt))
			continue ;
		p = o->e[print_order[i]];
		while (p)
			if ((r = prt(v, *(t_tag*)p->content)) != SUCCESS)
				return (r);
			else
				p = p->next;
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
						e_d,
						e_p};

	if (flgs & O_SHOW)
		return (print_obj_groups(o, print_order, e_seg_sz - 1, v));
	return (SUCCESS);
}
