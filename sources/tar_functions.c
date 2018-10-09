#include "scene.h"

void					free_tar(
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

int						clone_tar(
	t_s_ta *ta,
	void ***ret)
{
	size_t const	sz = ta->e_sz * TAS;
	void			**p;
	size_t			i;

	*ret = 0;
	if (!(p = malloc(sizeof(void*) * ta->ar_sz)))
		return (SYS_ERR);
	i = -1;
	while (++i < ta->ar_sz)
		if (!(p[i] = malloc(sz)))
		{
			free_tar(p, i, ta->e_sz);
			return (SYS_ERR);
		}
		else
			ft_memcpy(p[i], ta->ar[i], sz);
	*ret = p;
	return (SUCCESS);
}
