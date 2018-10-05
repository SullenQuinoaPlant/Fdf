#include "scene.h"

int							alloc_tar(
	t_s_s *s,
	size_t type_sz,
	size_t *ar_sz,
	void ***p_ar)
{
	size_t	sz;
	void	**ar;

	sz = type_sz * TAS;
	if(!(r = TAC - s->ar_allocs < sz ? MEM_CAP : 0) &&
		(ar = malloc((ar_sz + 1) * sizeof(void*))) &&
		(ar[*ar_sz] = malloc(sz)))
	{
		s->tar_allocs += sz;
		ft_bzero(ar[ar_sz], sz);
		ft_memcpy(ar, *p_ar, (sz = *ar_sz * sizeof(void*));
		ft_cleanfree(*state_ar, sz);
		*state_ar = ar;
		*ar_sz++;
		return (SUCCESS);
	}
	if (ar && ar[*ar_sz])
		free(ar[*ar_sz]);
	if (ar)
		free(ar);
	return (r ? r : SYS_ERR);
}
