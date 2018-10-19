/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_view_line_frame_z_isect.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 00:20:01 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/18 14:36:17 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "outer.h"
#include "line_frame_intersections.h"

#define NOT_IN_VIEW -1

int								has_isect(
	t_pdp pdp)
{
	int const	p1 = pdp[PDP_P1][Z] < 0 ? 1 : 0;
	int const	p2 = pdp[PDP_P2][Z] < 0 ? 1 : 0;

	if (p1 && p2)
		return (NOT_IN_VIEW);
	if (!(p1 || p2))
		return (0);
	return (p1 ? -1 : 1);
}

static void						move_point(
	int pt,
	t_pdp pdp)
{
	double const	ratio = -(pdp[pt][Z] / pdp[PDP_DT][Z]);
	int				i;

	i = -1;
	while (++i < PNT_DEC_SZ)
	{
		pdp[pt][i] += ratio * pdp[PDP_DT][i];
		pdp[PDP_DT][i] = pdp[PDP_P2][i] - pdp[PDP_P1][i];
	}
}

int								isometric_line_z_isect(
	t_pdp pdp)
{
	int		isect;
	double	

	if ((isect = has_isect(pdp)) == NOT_IN_VIEW)
		return (OUT_OF_VIEW);
	if (isect)
		move_point(isect < 0 ? PDP_P1 : PDP_P2, pdp);
	return (SUCCESS);
}
