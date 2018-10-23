#include "scene.h"

size_t						get_ve_size(
	t_e_seg g)
{
	size_t const	sizes[e_seg_sz] = {
		sizeof(t_s_pp),
		sizeof(t_s_dp),
		sizeof(t_s_lp),
		sizeof(t_s_ap),
		sizeof(t_s_fp),
		sizeof(t_s_op)};

	if (g == e_seg_null)
		return (0);
	return (sizes[g]);
}

void						*get_ve_tag(
	t_s_sv const *v,
	t_e_seg g,
	t_tag t)
{
	t_tag const			ar_tag = t >> TPS;
	t_tag const 		e_tag = t & TPM;
	t_s_ve const *const	tsve = &v->e[g];
	void				*p;

	p = tsve->ar[ar_tag] + tsve->e_sz * e_tag;
	return (p);
}
