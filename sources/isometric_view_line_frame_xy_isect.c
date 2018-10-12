/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_view_line_frame_xy_isect.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 23:53:24 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/12 23:59:00 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_typedefs.h"
#include "scene.h"
#include "isometric_view_line_frame_isect.h"

/*
**Get intersection points between the lines that prolong the viewing frame
** and the line we want to draw.
**
** x = 0
** y = 0
** y = w - 1
** x = h - 1
*/

static void						filter_xy_visible(
	t_s_sv *v,
	double (*isect)[DIMS],
{
	double const	h = (double)v->h;
	double const	w = (double)v->w;
	double			(*p)[DIMS];
	int				i;
	int				j;

	j = 0;
	i = -1;
	while (i--)
	{
		p = isect[isec_count];
		if (p[X] <= h && p[Y]
	}
}

static void						filter_p1p2_dir(

static void						filter_isects(
	t_s_sv *v,
	double pnd[3][DIMS + ARGBS],
	int pt_ct,
	doube isect[ISEC_CT][DIMS + ARGBS])
{
	int		valid[ISEC_CT];

	ft_bzero(valid, sizeof(valid));
	filter_xy_visible(v, isect, valid);
	filter_p1p2_dir(pnd, isect, valid);
	filter

}

/*
**If onyl one of the two 'pnd' points is within the view
**	frame, that point must be at position P1.
**
**Abbreviations:
** - valid : number of valid points, either 1 or 0
**		if 1, the valid point is in position P1 of 'pnd'.
** - pnd : points and delta. see .h.
** - isect : intersections
** - d : delta
** - p : point
** - r : ratio
*/
void							isometric_line_xy_isect(
	t_s_sv *v,
	int valid,
	double pnd[3][DIMS + ARGBS])
{
	double	isect[ISEC_CT][DIMS + ARGBS];
	double	d;
	double	p;
	double	r;
	int		i;

	i = 0;
	if ((d = pnd[DT][X]))
	{
		p = pnd[P1][X];
		set_mult_dims_arbg(pnd[P1], pnd[DT], (r = -p / d), isect[i++]);
		r = ((double)(v->w - 1) - p) / d;
		set_and_multiply(pnd, pnd[DT], r, isect[i++]);
	}
	if ((d = pnd[DT][Y]))
	{
		p = pnd[P1][Y];
		set_and_multiply(pnd, pnd[DT], (r = -p / d)), isect[i++]);
		r = ((double)(v->h - 1) - p) / d;
		set_and_multiply(pnd, pnd[DT], r, isect[i++]);
	}
	i = filter_isects(v, pnd, i, isect);
}
