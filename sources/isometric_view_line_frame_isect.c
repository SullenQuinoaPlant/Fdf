/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_view_line_frame_isect.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 23:33:51 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/12 23:22:04 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_typedefs.h"
#include "scene.h"
#include "isometric_view_line_frame_isect.h"

static void						set_and_multiply(
	double *src,
	double *deltas,
	double ratio,
	double *dest)
{
	int		i;

	ft_memcpy(dest, src, sizeof(double) * DIMS);
	int = -1;
	while (++i < DIMS)
		dest[i] += ratio * deltas[i];;
}
/*
**Get intersection points between the lines that prolong the viewing frame
** and the line we want to draw.
**
** x = 0
** y = 0
** y = w - 1
** x = h - 1
**
** abbreviations:
** - dlt : deltas
*/

static void						filter_isections_visible(
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

static void						filter_isections_zaxis(

	double (*isecs)[DIMS])

static void						filter_isects(
	t_s_sv *v,
	double pnd[3][DIMS + ARGBS],
	int pt_ct,
	doube isect[ISEC_CT][DIMS + ARGBS])
{
	int		i;
	int		j;

	i = -1;
	while (++i < 
}

/*
**If onyl one of the two 'pnd' points is within the view
**	frame, that point must be at position P1.
**
**Abbreviations:
** - pnd : points and delta. see .h.
** - isect : intersections
** - d : delta
** - p : point
** - r : ratio
*/
void							isometric_line_isect(
static int						isometric_intersections(
	t_s_sv *v,
	double pnd[3][DIMS + ARGBS],
	t_vpos *ret)
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
		set_and_multiply(pnd, pnd[DT], (r = -p / d), isect[i++]);
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
	stuff_res(pnd, isect, i, res);
}
