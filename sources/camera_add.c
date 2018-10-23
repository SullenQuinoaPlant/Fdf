#include "functions.h"
#include "scene.h"

/*
** It is expected that the new camera will be used, so the returned
**	structure has its reference count set to one.
**
** Abbreviations :
** - cts : coordinate transforms
** - ct_ct : coordinate transform count
*/
static t_s_pctr			*cleanup(
	t_s_pctr *p)
{
	t_s_pctr	*prv;

	prv = p->prv;
	while ((p = prv))
	{
		prv = p->prv;
		free(p);
	}
	return (0);
}

static t_s_pctr			*rewind(
	t_s_pctr *p)
{
	t_s_pctr	*nxt;

	nxt = p;
	while ((p = p->prv))
	{
		p->nxt = nxt;
		nxt = p;
	}
	return (nxt);
}

t_s_pctr				*add_camera(
	t_pctrm const *cts,
	int ct_ct,
	t_s_pctr **at)
{
	t_s_pctr	dummy;
	t_pctrm		mash[2];
	t_s_pctr	*p;
	int			tic;

	set_tpctrm_identity(*(mash + (tic = 0)));
	ft_bzero(&dummy, sizeof(t_s_pctr));
	dummy.refs = 1;
	while (ct_ct--)
	{
		ft_memcpy(dummy.own, *cts, sizeof(t_pctrm));
		tpctrm_mult(*(mash + tic), *cts++, *(mash + !tic));
		ft_memcpy(dummy.mashed, *(mash + (tic = !tic)), sizeof(t_pctrm));
		p = 0;
		if (!(p = ring_expand(sizeof(t_s_pctr), &dummy, (void**)&p)))
			return (cleanup(&dummy));
		dummy.prv = p;
	}
	p = rewind(dummy.prv);
	if (*at)
		p->prv = (**at).prv;
	ring_insert(p, (void**)at);
	return (dummy.prv);
}
