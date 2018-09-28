#include "scene.h"

/*
**Add tagged array to scene.
** star: Scene Tagged ARay
*/
int					add_star(
	t_tar_adder f,
	size_t ar_sz,
	t_s_s *s)
{
	int		r;

	if ((r = (*f)(s)) == SUCCESS)
	{
		s->nxt_allocs++;
		s->ar_allocs += ar_sz;
	}
	return (r);
}
