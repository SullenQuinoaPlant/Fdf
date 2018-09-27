#include "scene.h"

void				free_tssl(
	t_s_sl *lines)
{
	t_s_l *const	lim = *lines->ar + lines->ar_sz;
	t_s_l			*p;

	p = *lines->ar;
	while (p < lim)
		ft_cleanfree(p, TAG_AR_SZ * sizeof(t_s_l));
	ft_cleanfree(lines->ar, sizeof(t_s_l*) * lines->ar_sz);
}

void				free_tssa(
	t_s_sa *areas)
{
	t_s_a *const	lim = *areas->ar + areas->ar_sz;
	t_s_a			*p;

	p = *areas->ar;
	while (p < lim)
		ft_cleanfree(p, TAG_AR_SZ * sizeof(t_s_a));
	ft_cleanfree(areas->ar, sizeof(t_s_a*) * areas->ar_sz);
}

void				free_tsso(
	t_s_so *areas)
{
	t_s_o *const	lim = *objects->ar + objects->ar_sz;
	t_s_o			*p;

	p = *objects->ar;
	while (p < lim)
		ft_cleanfree(p, TAG_AR_SZ * sizeof(t_s_o));
	ft_cleanfree(areas->ar, sizeof(t_s_o*) * areas->ar_sz);
}
