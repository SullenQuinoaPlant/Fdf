#include "parsed.h"

static void				free_tssbi(
	t_s_sbi *tssbi)
{
	t_tssbi_freer	far[e_sit_sz] = {
		0,
		free_tscpgfxyrz
	};
	t_ssbi_freer	f;

	r = SUCCESS;
	if ((f = far[tssbi->type](tssbi))
		r = f(tssbi);
	ft_cleanfree(tssbi, sizeof(t_s_sbi));
}

void					free_tssbi_str(
	t_s_sbi *str)
{
	t_s_sbi *const	strt = str;

	while (str)
		free_tssbi(str++);
}
