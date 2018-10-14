#include "scene.h"

t_s_pctr				*add_camera(
	t_pctrm	*trs,
	int ct,
	t_s_s *s)
{
	t_s_pctr	dummy;
	t_pctrm		mash[2];
	t_s_pctr	**prv;

	prv = &s->ct;
	ft_bzero(mash, sizeof(mash));
	dummy.prv = 0;
	dummy.nxt = 0;
	dummy.view_ct = 0;
	while (ct--)
	{
		ft_memcpy(&dummy.own_tr, trs, sizeof(t_pctrm));
		tic = ct & 1 ? 0 : 1;
		tpctrm_mult(mash + (tic = ct & 1 ? 0 : 1), trs, mash + !tic);
		ft_memcpy(dummy.mashed_tr, mash + !tic, sizeof(t_pctrm)); 
		if (ring_expand(sizeof(t_s_pctr), &dummy, &(*prv)) != RING_SUCCESS)
			return (0);
		dummy.prv = *prv;
		dummy.prv->view_ct = 1;
		trs++;
	}
	return (dummy.prv);
}
