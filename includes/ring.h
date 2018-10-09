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

# define RING_SYS_ERR -1
# define RING_SUCCESS 0

#endif
