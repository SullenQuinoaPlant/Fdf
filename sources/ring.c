#include <stdlib.h>
#include "ring.h"

void					ring_insert(
	void *insertee,
	void **p_ring)
{
	t_s_ring *const	ins = insertee;
	t_s_ring *const	here = *p_ring;

	if (here)
	{
		*ins = (t_s_ring){here, here->nxt};
		ins->nxt->prv = ins;
		here->nxt = ins;
	}
	else
		*ins = (t_s_ring){ins, ins};
	*p_ring = ins->prv;
}

void					*ring_expand(
	size_t container_sz,
	void *content,
	void **p_ring)
{
	void	*p;

	if (!(p = malloc(container_sz)))
		return (0);
	if (content)
		ft_memcpy(p, content, container_sz);
	else
		ft_bzero(p, container_sz);
	ring_insert(p, p_ring);
	return (p);
}

void					ring_free(
	size_t container_sz,
	void (*del)(void*, size_t),
	void **p_ring)
{
	t_s_ring	*p;
	t_s_ring	*nxt;

	if (!(p = *p_ring))
		return ;
	del = del ? del : &ft_cleanfree;
	nxt = p;
	while ((p = nxt))
	{
		if ((nxt = p->nxt) == p)
			nxt = 0;
		(*del)((void*)p, container_sz);
	}
	*p_ring = 0;
}

void					ring_shrink(
	size_t container_sz,
	void (*del)(void*, size_t),
	void **p_at)
{
	t_s_ring *const	at = *p_at;

	if (!at)
		return ;
	*p_at = at->prv == at ? 0 : at->prv;
	at->nxt->prv = at->prv;
	at->prv->nxt = at->nxt;
	del = del ? del : &ft_cleanfree;
	(*del)((void*)at, container_sz);
}

int						ring_clone(
	size_t c_sz,
	void *clonee,
	void **ret)
{
	t_s_ring *const	lim = clonee;
	t_s_ring		*p;
	t_s_ring		*petri;
	int				r;

	*ret = 0;
	if (!(p = clonee))
		return (RING_SUCCESS);
	while (ring_expand(c_sz, p, (void**)&petri) &&
		(p = p->nxt) != lim)
		;
	if ((r = p == lim ? RING_SUCCESS : RING_SYS_ERR) != RING_SUCCESS)
		ring_free(c_sz, 0, (void**)&petri);
	else
		*ret = petri;
	return (r);
}

int						ring_apply(
	t_ring rg,
	t_ringapply f,
	void *f_arg)
{
	t_s_ring *const	strt = (t_s_ring*)rg;
	t_s_ring		*p;
	int				r;

	if (!(p = rg))
		return (RING_SUCCESS);
	while ((r = (*f)(f_arg, p)) == RING_SUCCESS)
		if ((p = p->nxt) == strt)
			break;
	return (r);
}
