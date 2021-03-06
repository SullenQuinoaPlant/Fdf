#include "functions.h"
#include "scene.h"

void						*get_se_tag(
	t_s_s const *s,
	t_e_seg g,
	t_tag t)
{
	t_tag const			ar_tag = t >> TPS;
	t_tag const 		e_tag = t & TPM;
	t_s_se const *const	tsse = &s->e[g];
	void				*p;

	p = tsse->ar[ar_tag] + tsse->e_sz * e_tag;
	return (p);
}

void						*get_se_ij(
	t_s_s const *s,
	t_e_seg g,
	size_t i,
	size_t j)
{
	t_s_se const *const	tsse = &s->e[g];

	return (tsse->ar[i] + tsse->e_sz * j);
}

int							initiate_se_release(
	void *se)
{
	t_refct *const	refct = (int*)se;

	if (*refct > 0)
	{
		*refct *= -1;
		return (SUCCESS);
	}
	return (REFCOUNT_INCOHERENT);
}
