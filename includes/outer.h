/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 01:07:39 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/15 08:40:51 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTER_H
# define OUTER_H

# include <stddef.h>
# include <stdint.h>
# include <limits.h>
# include "libft.h"
# include "ring.h"

# define SYS_ERR -1
# define SUCCESS 0
# define BAD_ARGS 1
# define MEM_CAP 2
# define BAD_INFILE 3
# define OUT_OF_VIEW 4

/*
**Space dimensions:
*/
# define DIMS 3
# define VIEW_DIMS 2

/*
**Color bytes:
*/
# define ARGBS 4

/*
**Pixel decomposition:
**Where a pixel is understood to be a set of coordinates,
**	associated with the color to put at these coordinates.
*/
# define PXL_DEC_SZ ARGBS + DIMS
/*
**Sometimes we put the coordinates first:
*/
# define PXL_DEC_DIM_OFFSET ARGBS
# define PDDO PXL_DEC_DIM_OFFSET
/*
**Sometimes not:
*/
# define PXL_DEC_ARGB_OFFSET DIMS
# define PDAO PXL_DEC_ARBG_OFFSET

#endif
