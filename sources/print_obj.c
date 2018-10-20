#include "functions.h"
#include "scene.h"

static void					print_listed_elements(
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
	t_e_seg const	print_order[e_seg_sz] = {
		e_o, e_f, e_l, e_a, e_d};
	t_e_seg			g;
	int				i;
	t_list			*p;

	i = -1;
	while (++i < e_seg_sz - 1)
	{
		g = print_order[i];
		p = o->e[print_order[i]];
		while (p)
		{
			(*printers[g])(v, *(t_tag*)p->content);
			p = p->next;
		}
	}
}

void						print_object(
	t_s_sv *v,
	t_tag t)
{

	t_s_op *const	op = &((t_s_op*)v->e[e_o].ar[t >> TPS])[t & TPM];
	t_s_o *const	o = &((t_s_o*)v->s->e[e_o].ar[t >> TPS])[t & TPM];
	uint8_t const	flgs = (o->flgs | op->set_flgs) & op->un_flgs;

	if (!(flgs & O_SHOW))
		return ;
	print_listed_elements(v, o);
}
