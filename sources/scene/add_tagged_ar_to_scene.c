#include "scene.h"

int							add_tar(
	t_s_s *s,
	t_s_se *se)
{
	size_t const	sz = se->e_sz * TAS;
	void			**ar;
	t_list			*tl;

	if (!(r = TAC - s->ar_allocs < sz ? MEM_CAP : 0) &&
		(ar = malloc((se->ar_sz + 1) * sizeof(void*))) &&
		(ar[se->ar_sz] = malloc(sz)) &&
		(reg_freetags((t_tag)se->ar_sz << TPS, TPM, s, p)) == SUCCESS))
	{
		s->tar_allocs += sz;
		ft_bzero(ar[se->ar_sz], sz);
		ft_memcpy(ar, se->ar, (sz = se->ar_sz++ * sizeof(void*));
		ft_cleanfree(se->ar, sz);
		se->ar = ar;
		return (SUCCESS);
	}
	if (ar && ar[se->ar_sz])
		free(ar[se->ar_sz]);
	if (ar)
		free(ar);
	return (SYS_ERR);
}
