#include "functions.h"

int							mirror_tsta_allocs(
	t_s_s *s,
	t_s_ta const *,
	t_s_ta *reflect)
{
	size_t const	oe_sz = out->e_sz
	size_t			ar_sz;
	size_t			sz;
	void			**ar;
	int				r;

	ar_sz = in->ar_sz;
	sz = out->e_sz * TAS * ar_sz;
	if(!(r = TAC - s->tar_allocs < sz ? MEM_CAP : 0) &&
		(ar = malloc(ar_sz * sizeof(void*))))
	{
		while (ar_sz-- && (r = tar_alloc(s, oe_sz, ar)) == SUCCESS)
		ft_memcpy(ar, *p_ar, (sz = prv_sz * sizeof(void*)));
		ft_cleanfree(*p_ar, sz);
		*p_ar = ar;
		(*ar_sz)++;
		return (SUCCESS);
	}
	if (ar && ar[prv_sz])
		free(ar[prv_sz]);
	if (ar)
		free(ar);
	return (r ? r : SYS_ERR);
