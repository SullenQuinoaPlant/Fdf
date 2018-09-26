#include "scene.h"

void					init_tsp_ar(
	t_s_p *ar)
{
	size_t	i;

	i = -1;
	while (++i < TAG_AR_SZ)
		ar[i] = (t_s_p){{0, 0, 0}, {0, 0, 0}, 0, i};
}

int						init_tssp(
	t_s_sp *p)
{
	int		r;

	r = SYS_ERR;
	p->ars = 0;
	if ((p->ars = malloc(sizeof(t_s_p*))) &&
		(*p->ars = malloc(sizeof(t_s_p * TAG_AR_SZ)) &&
		(r = init_tsp_ar(*p->ars) == SUCCESS)
	{
		*p = (t_s_sp){p->ars, 1, (t_tag)0};
		init_tsp_ar(*p->ars);
	}
	else if (p->ars)
	{
		free(*p->ars);
		free(p->ars);
	}
}
