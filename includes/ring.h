/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 03:32:59 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/07 03:33:00 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RING_H
# define RING_H

# include <stddef.h>
# include "libft.h"

/*
**Ring headers must be the initial member
**	of containing struct.
*/

typedef void	*t_ring;

typedef struct s_ring_header	t_s_ring;
struct					s_ring_header
{
	t_s_ring	*prv;
	t_s_ring	*nxt;
};

typedef int	(*t_ringapply)(void*, t_ring);

/*
**Ring functions:
*/

int						ring_apply(
	t_ring		ring,
	t_ringapply	f,
	void		*f_arg);

int						ring_clone(
	size_t	container_sz,
	void	*clonee,
	void	**ret);

void					*ring_expand(
	size_t	container_sz,
	void	*content,
	void	**p_ring);

void					ring_free(
	size_t	container_sz,
	void	(*del)(void*, size_t),
	void	**p_ring);

void					ring_insert(
	void	*insertee,
	void	**p_ring);

void					ring_shrink(
	size_t	container_sz,
	void	(*del)(void*, size_t),
	void	**p_at);

void					ring_simple_free(
	size_t	container_sz,
	void	**p_ring);

# define RING_SYS_ERR -1
# define RING_SUCCESS 0
# define RING_STOP 1

#endif
