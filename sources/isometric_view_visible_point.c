/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_view_visible_point.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 02:46:27 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/13 01:13:36 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_typedefs.h"
#include "scene.h"

int							is_iso_visible(
	t_s_sv *v,
	double pt[DIMS])
{
	double			d;

	if (((d = pt[X]) >= 0 || (t_vuint)d == 0) && d < v->w &&
		((d = pt[Y]) >= 0 || (t_vuint)d == 0) && d < v->h &&
		((d = pt[Z]) >= 0 || (t_vuint)d == 0))
		return (1);
	return (0);
}

int							is_iso_xy_visible(
	t_s_sv *v,
	double pt[DIMS])
{
	double			d;

	if (((d = pt[X]) >= 0 || (t_vuint)d == 0) && d < v->w &&
		((d = pt[Y]) >= 0 || (t_vuint)d == 0) && d < v->h)
		return (1);
	return (0);
}

int							is_iso_z_visible(
	t_s_sv *v,
	double pt[DIMS])
{
	double			d;

	if ((d = pt[Z]) >= 0 || (t_vuint)d == 0)
		return (1);
	return (0);
}
