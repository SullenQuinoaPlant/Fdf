#include "functions.h"
#include "scene.h"

static int					print_listed_elements(
	t_s_sv *v,
	t_s_o *o)
{
	t_printer const	printers[e_seg_sz] = {
		0,
		print_dot,
		print_line,
		print_arrow,
		print_fill,
		print_object};
	t_e_seg const	print_order[e_seg_sz - 1] = {
		e_o, e_f, e_l, e_a, e_d};
	int				i;
	t_list			*p;
	int				r;

	i = -1;
	while (++i < e_seg_sz - 1)
	{
		p = o->e[print_order[i]];
		while (p)
		{
			r = (*printers[print_order[i]])(v, *(t_tag*)p->content);
			if (r != SUCCESS)
				return (r);
			p = p->next;
		}
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

	if (flgs & O_SHOW)
		return (print_listed_elements(v, o));
	return (SUCCESS);
}
