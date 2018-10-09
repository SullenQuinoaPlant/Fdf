#include <stdlib.h>
#include "parse.h"

void					free_tscdgfxyrz(
	t_s_sbi *sbi)
{
	t_s_cdgfxyrz *const	p = (t_s_cdgfxyrz*)sbi->input;

	free(p->ar);
}
