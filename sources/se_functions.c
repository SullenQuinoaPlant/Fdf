#include "functions.h"

void					*get_se(
	t_s_s const *s,
	t_e_seg g,
	t_tag t)
{
	t_tag const		ar_tag = t >> TPS;
	t_tag const 	e_tag = t & TPM;
	t_s_se *const	tsse = s->e[g];
	void			*p;

	p = tsse->ar[ar_tag] + tsse->e_sz * e_tag;
	return (p);
}
