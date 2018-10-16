#include "functions.h"
#include "scene.h"

/*
** It is expected that the new camera will be used, so the returned
**	structure has it's reference count set to one.
**
** Abbreviations :
** - cts : coordinate transforms
** - ct_ct : coordinate transform count
*/
t_s_pctr				*add_camera(
	t_pctrm *cts,
	int ct_ct,
	t_s_s *s)
{
	t_s_pctr	dummy;
	t_pctrm		mash[2];
	t_s_pctr	*prv;
	int			tic;
	int			r;

	prv = s->ct;
	ft_memcpy(mash[0], cts, sizeof(t_pctrm));
	ft_bzero(&dummy, sizeof(t_s_pctr));
	dummy.refs = 1;
	tic = 0;
	while (ct_ct--)
	{
		ft_memcpy(&dummy.own, cts, sizeof(t_pctrm));
		tpctrm_mult(*(mash + (tic = !tic), cts, *(mash + !tic));//THIS IS BAD
		ft_memcpy(dummy.mashed, mash + !tic, sizeof(t_pctrm)); 
		r = ring_expand(sizeof(t_s_pctr), &dummy, &prv);
		if (r != RING_SUCCESS)
			return (0);
		dummy.prv = prv;
		cts++;
	}
	return (dummy.prv);
}
