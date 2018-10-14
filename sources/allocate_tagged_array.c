/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_tagged_array.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 03:42:08 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/14 07:21:27 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

int							tar_alloc(
	t_s_s *s,
	size_t type_sz,
	void **p_alloc)
{
	size_t const	sz = type_sz * TAS;
	int		r;

	*p_alloc = 0;
	if(!(r = TAC - s->tar_allocs < sz ? MEM_CAP : 0) &&
		(*p_alloc = malloc(sz)))
	{
		s->tar_allocs += sz;
		return (SUCCESS);
	}
	return (r ? r : SYS_ERR);
}

int							inc_tar_alloc(
	t_s_s *s,
	size_t type_sz,
	size_t *ar_sz,
	void ***p_ar)
{
	size_t const	prv_sz = *ar_sz;
	size_t			sz;
	void			**ar;
	int				r;

	sz = type_sz * TAS;
	ar = 0;
	if(!(r = TAC - s->tar_allocs < sz ? MEM_CAP : 0) &&
		(ar = malloc((prv_sz + 1) * sizeof(void*))) &&
		(r = tar_alloc(s, type_sz, &ar[prv_sz])) == SUCCESS)
	{
		ft_memcpy(ar, *p_ar, (sz = prv_sz * sizeof(void*)));
		ft_cleanfree(*p_ar, sz);
		*p_ar = ar;
		(*ar_sz)++;
		return (SUCCESS);
	}
	if (ar && ar[prv_sz])
		free(ar[prv_sz]);
	if (ar)
		free(ar);
	return (r ? r : SYS_ERR);
}
