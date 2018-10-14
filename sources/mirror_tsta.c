#include "functions.h"

int							mirror_tsta_allocs(
	t_s_s *s,
	t_s_ta const *in,
	t_s_ta *out)
{
	size_t			ar_sz;
	size_t			sz;
	int				r;

	ar_sz = in->ar_sz;
	sz = out->e_sz * TAS * ar_sz;
	if(!(r = TAC - s->tar_allocs < sz ? MEM_CAP : 0) &&
		(out->ar = malloc(ar_sz * sizeof(void*))))
	{
		while (ar_sz--)
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
