#include "scene.h"

t_s_pctr						*get_camera_component(
	t_s_pctr *cam,
	int yrpztr)
{
	int		i;

	i = CYRPZ - yrpztr;
	while (--i)
		if (!(cam = cam->prv))
			break ;
	return (cam);
}

static void						update_mashed(
	void *unused,
	t_ring p_tspctr)
{
	t_s_pctr *const	chgee = (t_s_pctr*)p_tspctr;
	t_s_pctr *const	prv = chgee->prv;
	t_s_pctr		*nxt;

	(void)unused;
	tpctrm_mult(prv->mashed, chgee->own, chgee->mashed);
	chgee->tick++;
	if ((nxt = chgee->nxt))
		ring_apply(nxt, update_mashed, 0);
}

void							chg_tpctrm(
	t_s_pctrm new,
	int yrpztr,
	t_s_pctr *chgee)
{
	t_s_pctr	*prv;
	t_s_pctr	*nxt;

	ft_memcpy(chgee->own, new, sizeof(t_s_pctrm));
	if (!(prv = chgee->prv))
		tpctrm_mult(prv->mashed, new, chgee->mashed);
	else
		ft_memcpy(chgee->mashed, new, sizeof(t_s_pctrm));
	chgee->tick++;
	if ((nxt = chgee->nxt))
		ring_apply(nxt, update_mashed, 0);
}
