#include "scene.h"

void						free_free_tar(
	void **ar,
	size_t ar_sz,
	size_t e_sz)
{
	size_t const	sz = TAS * e_sz;
	void **const	lim = ar + ar_sz;
	void			**p;

	if (!*(p = ar))
		return ;
	while (p < lim)
		ft_cleanfree(*p++, sz);
	ft_cleanfree(ar, sizeof(void*) * ar_sz);
}

void						free_tar(
	void **ar,
	size_t ar_sz,
	size_t e_sz,
	t_s_s *s)
{
	free_free_tar(ar, ar_sz, e_sz);
	s->tar_allocs -= ar_sz * e_sz;
}

int							tar_alloc(
	t_s_s *s,
	size_t type_sz,
	void **p_alloc)
{
	size_t const	sz = type_sz * TAS;
	int		r;

	*p_alloc = 0;
	if(!(r = TAC - s->tar_allocs < sz ? MEM_CAP : 0) &&
		(*p_alloc = malloc(sz)))
	{
		s->tar_allocs += sz;
		return (SUCCESS);
	}
	return (r ? r : SYS_ERR);
}

int							inc_tar_alloc(
	t_s_s *s,
	size_t type_sz,
	size_t *ar_sz,
	void ***p_ar)
{
	size_t const	prv_sz = *ar_sz;
	size_t			sz;
	void			**ar;
	int				r;

	sz = type_sz * TAS;
	ar = 0;
	if(!(r = TAC - s->tar_allocs < sz ? MEM_CAP : 0) &&
		(ar = malloc((prv_sz + 1) * sizeof(void*))) &&
		(r = tar_alloc(s, type_sz, &ar[prv_sz])) == SUCCESS)
	{
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
}
