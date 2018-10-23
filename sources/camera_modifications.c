#include "functions.h"
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

static int						update_mashed(
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
	return (RING_SUCCESS);
}

static void						chg_tpctrm(
	t_pctrm new,
	t_s_pctr *chgee)
{
	t_s_pctr	*prv;
	t_s_pctr	*nxt;

	ft_memcpy(chgee->own, new, sizeof(t_pctrm));
	if (!(prv = chgee->prv))
		tpctrm_mult(prv->mashed, new, chgee->mashed);
	else
		ft_memcpy(chgee->mashed, new, sizeof(t_pctrm));
	chgee->tick++;
	if ((nxt = chgee->nxt))
		ring_apply(nxt, update_mashed, 0);
}

void							cam_tr(
	t_xyz tr,
	t_s_sv *v)
{
	t_s_pctr *const		trz = get_camera_component(v->ct, TRZ);
	t_pctrm *const	old = &trz->own;
	t_pctrm			new;
	int					i;

	ft_memcpy(new, old, sizeof(t_pctrm));
	i = -1;
	while (++i < DIMS)
		new[TPCTRM_TR][i] = (*old)[TPCTRM_TR][i] - tr[i];
	chg_tpctrm(new, trz);
}

void							cam_zoom(
	double ratio,
	t_s_sv *v)
{
	t_s_pctr *const		trz = get_camera_component(v->ct, TRZ);
	t_pctrm *const	old = &trz->own;
	t_pctrm			new;

	ft_memcpy(new, old, sizeof(t_pctrm));
	tpctrm_scalar_mult(ratio, new);
	chg_tpctrm(new, trz);
}
