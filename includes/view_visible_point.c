/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_visible_point.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 02:46:27 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/12 03:14:36 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_typedefs.h"
#include "scene.h"

static int						is_visible(
	t_vuint w,
	t_vuint h,
	double pt[DIMS])
{
	double const	w_offset = (double)(w / 2);
	double const	h_offset = (double)(h / 2);
	double const	w_max = (double)w;
	double const	h_max = (double)h;
	double			d;

	if ((d = pt[X] + w_offset) < w_max && d >= 0 &&
		(d = pt[Y] + y_offset) < y_max && d >= 0 &&
		pt[Z] >= 0)
		return (1);
	return (0);
}
