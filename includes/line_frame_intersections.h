/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_frame_intersections.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 00:41:08 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/13 05:05:08 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_FRAME_INTERSECTIONS_H
# define LINE_FRAME_INTERSECTIONS_H

# include "outer.h"

/*
** A line may cross the rectangular views' boundaries four times when we extend
** these to infinity. Therefore isect[4].
*/
# define ISEC_CT 4

/*
** Indexes of:
** - first point, 
** - delta between first point and second point, 
** - second point
** in the stupid mash-up array
*/
# define P1 0
# define DELTA 1
# define DT DELTA
# define P2 2

# define DBL_DIMS_SZ (sizeof(double) * DIMS)
# define DBL_ARGBS_SZ (sizeof(double) * ARGBS)
# define DBL_DIMS_ARGBS_SZ DBL_DIMS_SZ + DBL_ARGBS_SZ

#define ARGB_OFFSET DIMS

#endif
