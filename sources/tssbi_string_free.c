#include "functions.h"
#include "scene.h"
#include "parse.h"

static void				free_tssbi(
	t_s_sbi *tssbi)
{
	t_tssbi_freer	far[e_sit_sz] = {
		0,
		free_tscdgfxyrz
	};
	t_tssbi_freer	f;

	if ((f = far[tssbi->type]))
		f(tssbi->input);
	free(tssbi);
}

void					free_tssbi_str(
	t_s_sbi **str)
{
	t_s_sbi **const	save = str;
	t_s_sbi			*p;

	while ((p = *str++))
		free_tssbi(p);
	*save = 0;
}
