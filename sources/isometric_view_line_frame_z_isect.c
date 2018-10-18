/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_view_line_frame_z_isect.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 00:20:01 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/18 12:58:12 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "outer.h"
#include "line_frame_intersections.h"

#define NOT_IN_VIEW -1

int								has_isect(
	t_pnd pnd)
{
	int const	p1 = pnd[P1][Z] < 0 ? 1 : 0;
	int const	p2 = pnd[P2][Z] < 0 ? 1 : 0;

	if (p1 && p2)
		return (NOT_IN_VIEW);
	if (!p1 && !p2)
		return (0);
	return (1);
}

static void						move_point(
	int pt,
	t_pnd pnd)
{
	double const	ratio = -(pnd[pt][Z] / pnd[DT][Z]);
	int				i;

	i = -1;
	while (++i < PNT_DEC_SZ)
	{
		pnd[pt][i] += ratio * pnd[DT][i];
		pnd[DT][i] = pnd[P2][i] - pnd[P1][i];
	}
}

void							isometric_line_z_isect(
	t_pnd pwd)
{
	int		isect;
	double	

	if ((isect = has_isect(pnd)) == NOT_IN_VIEW)
		return (OUT_OF_VIEW);
	if (isect)
		move_point(p1 ? P1 : P2, pnd);
}
