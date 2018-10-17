/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_frame_intersections.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 00:41:08 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/15 08:45:38 by nmauvari         ###   ########.fr       */
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
** (t_pdp) stands for 'point, delta, point'
** Indexes of:
** - first point, (index P1)
** - delta between first point and second point (P2 - P1), (index DT)
** - second point (index P2)
*/
# define PDP_P1 0
# define PDP_DT 1
# define PDP_P2 2
# define PDP_SZ 3

typedef double	t_pdp[PDP_SZ][PXL_DEC_SZ];

#endif
