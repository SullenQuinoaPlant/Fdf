#include "scene.h"

void					free_tar(
	void **ar,
	size_t ar_sz,
	size_t e_sz)
{
	size_t const	sz = TAS * e_sz;
	void *const		lim = ar + ar_sz;
	void			**p;

	f (!*(p = ar))
	while (p < lim)
		ft_cleanfree(*p++, sz);
	ft_cleanfree(ar, sizeof(void*) * ar_sz);
}
