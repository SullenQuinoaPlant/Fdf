/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_view_line_frame_xy_isect.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 23:53:24 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/30 01:40:25 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "scene.h"
#include "line_frame_intersections.h"

/*
**Get intersection points between the lines that prolong the viewing frame
** and the line we want to draw.
**
** x = w / 2
** y = h / 2 
** y = w / 2 - 1 or 0
** x = h / 2 - 1 or 0
*/

static void						filter_xy_visible(
	t_s_sv *v,
	int pt_ct,
	t_pdd isect[ISEC_CT],
	int valid[ISEC_CT])
{
	while (pt_ct--)
		if (is_iso_xy_visible(v, isect[pt_ct]))
			valid[pt_ct] = 1;
}

static void						filter_p1p2_dir(
	int pt_ct,
	t_pdd isect[ISEC_CT],
	t_pdp pdp,
	int valid[ISEC_CT])
{
	int		j;

	while (pt_ct--)
	{
		if (!valid[pt_ct])
			continue ;
		j = 0;
		while (j < DIMS &&
			sign(pdp[PDP_DT][j]) == sign(isect[pt_ct][j] - pdp[PDP_P1][j]))
			j++;
		if (j != DIMS)
			valid[pt_ct] = 0;
	}
}

/*
** If P1 is valid, then there is only one valid intersection point
** that remains after filtering.
*/

static int						filter_isects(
	t_s_sv *v,
	int pt_ct,
	t_pdd isect[ISEC_CT],
	t_pdp pdp)
{
	int		valid[ISEC_CT];
	int		i;
	int		j;

	ft_bzero(valid, sizeof(valid));
	filter_xy_visible(v, pt_ct, isect, valid);
	filter_p1p2_dir(pt_ct, pdp, isect, valid);
	i = -1;
	j = PDP_P2;
	while (++i < pt_ct)
		if (valid[i])
		{
			ft_memcpy(pdp[j], isect[i], sizeof(pdp[PDP_P1]));
			j = PDP_P1;
		}
	return (j != PDP_P2 ? SUCCESS : OUT_OF_VIEW);
}

/*
**If onyl one of the two 'pdp' points is within the view
**	frame, that point must be at position P1.
**
**Abbreviations:
** - pdp : points and delta. see .h.
** - isect : intersections
** - d : delta
** - p : point
** - r : ratio
*/

int								isometric_line_xy_isect(
	t_s_sv *v,
	t_pdp pdp)
{
	t_pdd	isect[ISEC_CT];
	double	d;
	double	p;
	double	r;
	int		pt_ct;

	pt_ct = 0;
	if ((d = pdp[PDP_DT][X]))
	{
		p = pdp[PDP_P1][X];
		r = (-(double)(v->w / 2) - p) / d;
		set_mult_pnt_dec(pdp[PDP_P1], pdp[PDP_DT], r, isect[pt_ct++]);
		r = ((double)(v->w / 2 - (v->w & 1 ? 0 : 1)) - p) / d;
		set_mult_pnt_dec(pdp[PDP_P1], pdp[PDP_DT], r, isect[pt_ct++]);
	}
	if ((d = pdp[PDP_DT][Y]))
	{
		p = pdp[PDP_P1][Y];
		r = (-(double)(v->h / 2) - p) / d;
		set_mult_pnt_dec(pdp[PDP_P1], pdp[PDP_DT], r, isect[pt_ct++]);
		r = ((double)(v->h / 2 - (v->w & 1 ? 0 : 1)) - p) / d;
		set_mult_pnt_dec(pdp[PDP_P1], pdp[PDP_DT], r, isect[pt_ct++]);
	}
	return (filter_isects(v, pt_ct, isect, pdp));
}
