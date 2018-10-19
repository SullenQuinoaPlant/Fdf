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

#include "functions.h"
#include "scene.h"

int							iso_dbl_within_dimsz(
	t_vuint const dim_sz,
	double d)
{
	t_vuint const	half = dim_sz / 2;
	int const		sign = d > 0 ? 1 : -1;
	int const		even = dim_sz & 0x1 ? 0 : 1;
	t_vuint			cast;
	int				ret;

	if ((d *= (double)sign) > (double)(TVUINT_MAX))
		return (0);
	cast = (t_vuint)d;
	if (even && sign == 1)
		ret = cast > half - 1 ? 0 : 1;
	else
		ret = cast > half ? 0 : 1;
	return (ret);
}

int							is_iso_visible(
	t_s_sv *v,
	t_xyz pt)
{
	if (iso_dbl_within_dimsz(v->w, pt[X]) &&
		iso_dbl_within_dimsz(v->h, pt[Y]) &&
		pt[Z] >= 0)
		return (1);
	return (0);
}

int							is_iso_xy_visible(
	t_s_sv *v,
	t_xyz pt)
{
	if (iso_dbl_within_dimsz(v->w, pt[X]) &&
		iso_dbl_within_dimsz(v->h, pt[Y]))
		return (1);
	return (0);
}

int							is_iso_z_visible(
	t_xyz pt)
{
	double			d;

	if ((d = pt[Z]) >= 0)
		return (1);
	return (0);
}
