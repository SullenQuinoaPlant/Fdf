/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_view_visible_point.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 02:46:27 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/13 04:36:34 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_typedefs.h"
#include "scene.h"

int							is_iso_visible(
	t_s_sv *v,
	t_xyz pt);
{
	if (dbl_within_dimsz(v->w, pt[X]) &&
		dbl_within_dimsz(v->h, pt[Y]) &&
		pt[Z] >= 0)
		return (1);
	return (0);
}

int							is_iso_xy_visible(
	t_s_sv *v,
	double pt[DIMS])
{
	if (dbl_within_dimsz(v->w, pt[X]) &&
		dbl_within_dimsz(v->h, pt[Y]))
		return (1);
	return (0);
}

int							is_iso_z_visible(
	double pt[DIMS])
{
	double			d;

	if ((d = pt[Z]) >= 0)
		return (1);
	return (0);
}
