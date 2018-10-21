#include <stdlib.h>
#include "parse.h"

void					free_tscdgfxyrz(
	void *input)
{
	t_s_cdgfxyrz *const	p = (t_s_cdgfxyrz*)input;
	size_t const		sz = p->x_sz * p->y_sz;

	ft_cleanfree(p->ar, sizeof(t_s_cxyd) * sz);
	free(input);
}
