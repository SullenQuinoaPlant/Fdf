#include "functions.h"

int							tsta_allocs(
	t_s_s *s,
	t_s_ta *ta)
{
	size_t const	e_sz = ta->e_sz
	size_t const	sz = e_sz * TAS * ta->ar_sz;
	size_t			ar_sz;
	void			**ar;
	int				r;

	ar_sz = ta->ar_sz;
	if(!(r = TAC - s->tar_allocs < sz ? MEM_CAP : 0) &&
		(ar = malloc(ar_sz * sizeof(void*))))
	{
		ta->ar = ar;
		while (ar_sz && (r = tar_alloc(s, e_sz, ar++)) == SUCCESS)
			ar_sz--;
	}
	if (!ar_sz)
		return (SUCCESS);
	if (ar)
		free_tar(ta->ar, ta->ar_sz - ar_sz)
	ta->ar = 0;
	return (r ? r : SYS_ERR);
}

int							mirror_tsta(
	t_s_s *s,
	t_s_ta const *model,
	size_t e_sz;
	t_s_ta *reflection)
{
	reflection->ar = 0;
	reflection->ar_sz = model->ar_sz;
	reflection->e_sz = e_sz;
	r = tsta_allocs(s, reflection);
	return (r);
}
