/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 01:07:39 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/24 22:21:00 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTER_H
# define OUTER_H

# include <stddef.h>
# include <stdint.h>
# include <limits.h>
# include "libft.h"
# include "ring.h"
# include "libgetnextline.h"

/*
**Return values:
*/

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
# define X 0
# define Y 1
# define Z 2

/*
**T: θ, in (xOy) plane, from x
**P: φ, from z to (xOy) plane.
**R: radius, from O.
*/

# define T 0
# define P 1
# define R 2

# define VIEW_DIMS 2

/*
**Color bytes:
*/

# define ARGBS 4

/*
**Pixel decomposition:
**Where a pixel is understood to be a set of coordinates,
**	in 2-dimensional view frame,
**	associated with the color to put at these coordinates.
**
**Point decomposition
**Where a point is understood to be a set of coordinates,
**	in 3-dimensional scene space,
**	associated with the color to put at these coordinates.
*/

/*
**# define PXL_DEC_SZ ARGBS + VIEW_DIMS
**# define PNT_DEC_SZ ARGBS + DIMS
*/

# define PXL_DEC_SZ 6
# define PNT_DEC_SZ 7

/*
**Sometimes we put the coordinates last:
*/

# define PXL_DEC_DIM_OFFSET ARGBS
# define PNT_DEC_DIM_OFFSET ARGBS
# define PDDO PXL_DEC_DIM_OFFSET

/*
**Sometimes not:
*/

# define PXL_DEC_ARGB_OFFSET VIEW_DIMS
# define PXDAO PXL_DEC_ARGB_OFFSET
# define PNT_DEC_ARGB_OFFSET DIMS
# define PTDAO PNT_DEC_ARGB_OFFSET

/*
**Mins and maxes:
*/

# define MIN 0
# define MAX 1
# define MIN_MAX_SZ 2
# define MIN_MAX_XYZ_PERMUTATION_COUNT 8
# define MMXYZPC MIN_MAX_XYZ_PERMUTATION_COUNT

/*
**Loop state constants:
*/

# define NOT_LOOPING 0
# define LOOPING 1
# define LOOP_LOCK 2

/*
**Default window name:
*/

# define DEFAULT_WDW_NAME "fdf window"

#endif
