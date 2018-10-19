#include "functions.h"
#include "scene.h"

static void					print_listed_elements(
	t_s_sv *v,
	t_s_o *o)
{
	t_printer const	printers[e_seg_sz] = {
		0,
		0,
		print_dot,
		print_line,
		print_arrow,
		print_fill,
		print_object};
	t_e_oeg		i;
	t_list		*p;

	i = e_ov;
	while (++i < e_oeg_sz)
	{
		p = o->e[i];
		while (p)
		{
			(*printers)(v, *(t_tag*)p->content);
			p = p->next;
		}
	}
}

void						print_obj(
	t_s_sv *v,
	t_tag t)
{

	t_s_op *const	op = &(v->e[e_so].ar[t >> TPS])[t & TPM];
	t_s_o *const	o = &(v->s->e[e_so].ar[t >> TPS])[t & TPM];
	uint8_t const	flgs = o->flgs | op->set_flgs & op->un_flgs;

	if (!(flgs & O_SHOW))
		return ;
	print_listed_elements(v, o);
}
