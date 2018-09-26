#include "scene.h"

void				tssp_free(
	t_s_sp *points)
{
	t_s_p *const	lim = *points->ar + points->ar_sz;
	t_s_p			*p;

	p = *points->ar;
	while (p < lim)
		ft_cleanfree(p, TAG_AR_SZ * sizeof(t_s_p));
	ft_cleanfree(points->ar, sizeof(t_s_p*) * points->ar_sz);
}
