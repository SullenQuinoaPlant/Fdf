#include "functions.h"
#include "scene.h"

int							tsta_allocs(
	t_s_s *s,
	t_s_ta *ta)
{
	size_t const	e_sz = ta->e_sz;
	size_t const	sz = e_sz * TAS * ta->ar_sz;
	size_t			ar_sz;
	void			**ar;
	int				r;

	ar_sz = ta->ar_sz;
	if(!(r = TAC - s->tar_allocs < sz ? MEM_CAP : 0) &&
		(ar = malloc(ar_sz * sizeof(void*))))
	{
		ta->ar = ar;
		while (ar_sz && (r = tar_alloc(s, e_sz, ar++)) == SUCCESS)
			ar_sz--;
	}
	if (!ar_sz)
		return (SUCCESS);
	if (ar)
		free_tar(ta->ar, ta->ar_sz - ar_sz, e_sz, s);
	ta->ar = 0;
	return (r ? r : SYS_ERR);
}

int							mirror_tsta(
	t_s_s *s,
	t_s_ta const *model,
	size_t e_sz,
	t_s_ta *reflection)
{
	int		r;

	reflection->ar = 0;
	reflection->ar_sz = model->ar_sz;
	reflection->e_sz = e_sz;
	r = tsta_allocs(s, reflection);
	return (r);
}

int						clone_tsta(
	t_s_ta *ta,
	t_s_ta *ret,
	t_s_s *s)
{
	size_t const	sz = ta->e_sz * TAS;
	size_t const	ttl_sz = sz * ta->ar_sz;
	void			**p;
	size_t			i;
	int				r;

	ret->ar = 0;
	if ((r = TAC - s->tar_allocs < ttl_sz ? MEM_CAP : 0) ||
		!(p = malloc(sizeof(void*) * ta->ar_sz)))
		return (r ? r : SYS_ERR);
	i = -1;
	while (++i < ta->ar_sz)
		if (!(p[i] = malloc(sz)))
		{
			free_free_tar(p, i, ta->e_sz);
			return (SYS_ERR);
		}
		else
			ft_memcpy(p[i], ta->ar[i], sz);
	ret->ar = p;
	s->tar_allocs += ttl_sz;
	return (SUCCESS);
}

/*
** It is assumed that the destination is compatible with the (t_s_ta) we are 
** 	copying from.
*/
void					copy_tsta(
	t_s_ta const *from,
	void **dest)
{
	size_t const	ar_sz = from->ar_sz;
	size_t const	sz = from->e_sz * TAS;
	void **const	lim = from->ar + ar_sz;
	void			**p;

	p = from->ar;
	while (p < lim)
		ft_memcpy(*dest++, *p++, sz);
}
