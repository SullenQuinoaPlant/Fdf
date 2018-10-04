#include <stdlib.h>
#include "ring.h"

int						ring_expand(
	size_t container_sz,
	void *content,
	void **p_ring)
{
	t_s_ring *const	prv = *p_ring;
	t_s_ring			*p;

	if (!(p = malloc(container_sz)))
		return (RING_SYS_ERR);
	if (content)
		ft_memcpy(p, content, container_sz);
	if (prv)
	{
		*p = (t_s_ring){prv, prv->nxt};
		p->nxt->prev = p;
		prv->nxt = p;
	}
	else
		*p = (t_s_ring){p, p};
	*p_ring = p;
	return (RING_SUCCESS);
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
		nxt = p->nxt;
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
	while ((r = ring_expand(c_sz, p, &petri)) == RING_SUCCESS &&
		(p = p->nxt) != lim)
		;
	if (r != RING_SUCCESS)
		ring_free(c_sz, 0, &petri);
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

	if (!*(p = rg))
		return (RING_SUCCESS);
	while ((r = (*f)(f_arg, p)) == RING_SUCCESS)
		if ((p = p->nxt) == strt)
			break;
	return (r);
}
