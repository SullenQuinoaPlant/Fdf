#include "parsed.h"

static void				free_tssbi(
	t_s_sbi *tssbi)
{
	t_tssbi_freer	f[e_sit_sz] = {
		0,
		free_tscpgfxyrz
	};

	r = f[tssbi->type](tssbi);
	ft_cleanfree(tssbi, sizeof(t_s_sbi));
}

void					free_tssbi_str(
	t_s_sbi *str)
{
	t_s_sbi *const	strt = str;

	while (str)
		free_tssbi(str++);
}
