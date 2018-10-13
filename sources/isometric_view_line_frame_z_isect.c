/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_view_line_frame_z_isect.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 00:20:01 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/13 05:14:45 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "outer.h"

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

void							isometric_line_z_isect(
	double pnd[3][DIMS + ARGBS])
{
	int		isect;
	t_pnd
	double	

	if ((isect = has_isect(pnd)) == NOT_VISIBLE)
		return (OUT_OF_VIEW);
	
}
