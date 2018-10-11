/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_projection_view_frame_intersections.          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 23:33:51 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/12 01:14:40 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_typedefs.h"
#include "scene.h"

#define ISEC_CT 4

static void						set_and_multiply(
	double *src,
	double mult,
	double *dest)
{
	int		i;

	ft_memcpy(dest, src, sizeof(double) * DIMS);
	int = -1;
	while (++i < DIMS)
		dest[i] *= mult;
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
	double (*isecs)[DIMS],
{
	double const	h = (double)v->h;
	double const	w = (double)v->w;
	double	(*p)[DIMS];
	int		i;
	int		j;

	j = 0;
	i = -1;
	while (i--)
	{
		p = isecs[isec_count];
		if (p[X] <= h && p[Y]
	}
}

static void						filter_isections_zaxis(

	double (*isecs)[DIMS])

static int						get_intersections(
	t_s_sv *v,
	t_u_slsa *const loa,
	t_u_spsv const *const *pts,
	double *ret)
{
	double	isect[ISEC_CT][DIMS + 1];
	t_tag	t;
	double	*p;
	int		i;

	ft_memcpy(dlt, (pts[(t = loa->ends[2]) >> TPS])[t & TPM].xyz, sizeof(dlt));
	p = (pts[(t = loa->ends[1]) >> TPS])[t & TPM].xyz;
	i = -1;
	while (++i < DIMS)
		dlt[i] -= p[i];
	i = 0;
	if (dlt[X])
	{
		set_and_multiply(p, -(p[X] / dlt[X]), &ret[i++]);
		set_and_multiply(p, ((double)(v->w - 1) - p[X]) / dlt[X]), &ret[i++]);
	}
	if (dlt[Y])
	{
		set_and_multiply(p, -(p[Y] / dlt[Y]), &ret[i++]);
		set_and_multiply(p, ((double)(v->h - 1) - p[Y]) / dlt[Y]), &ret[i++]);
	}
	filter_visible(v, ret);
	filter_valid(ends, ret);
}
