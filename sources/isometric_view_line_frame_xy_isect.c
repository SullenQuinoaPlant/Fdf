/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_view_line_frame_xy_isect.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 23:53:24 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/13 05:59:29 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_typedefs.h"
#include "scene.h"
#include "line_frame_intersections.h"

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
	int pt_ct,
	double isect[ISEC_CT][DIMS],
	int valid[ISEC_CT])
{
	while (pt_ct--)
		if (is_iso_xy_visible(v, isect[pt_ct]))
			valid[pt_ct] = 1;
}

static void						filter_p1p2_dir(
	int pt_ct,
	double isect[ISEC_CT][DIMS + ARGBS],
	double pnd[ISEC_CT][DIMS + ARGBS],
	int valid[ISEC_CT])
{
	int		j;

	while (pt_ct--)
	{
		if (!valid[pt_ct])
			continue ;
		j = 0;
		while (j < DIMS &&
			sign(pnd[DT][j]) == sign(isect[pt_ct][j] - pnd[P1][j]))
			j++;
		if (j != DIMS)
			valid[pt_ct] = 0;
	}
}

/*
** If P1 is valid, then there is only one valid intersection point
** that remains after filtering.
*/
static void						filter_isects(
	t_s_sv *v,
	int pt_ct,
	doube isect[ISEC_CT][DIMS + ARGBS],
	double pnd[3][DIMS + ARGBS])
{
	int		valid[ISEC_CT];
	int		i;
	int		j;

	ft_bzero(valid, sizeof(valid));
	filter_xy_visible(v, pt_ct, isect, valid);
	filter_p1p2_dir(pnd, pt_ct, isect, valid);
	i = -1;
	j = P2;
	while (++i < pt_ct)
		if (valid[i])
		{
			ft_memcpy(pnd[j], isect[i], sizeof(pnd[P1]));
			j = P1;
		}
	return (j != P2 ? SUCCES : OUT_OF_VIEW);
}

int	
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
int								isometric_line_xy_isect(
	t_s_sv *v,
	t_pnd pnd)
{
	double	isect[ISEC_CT][DIMS + ARGBS];
	double	d;
	double	p;
	double	r;
	int		pt_ct;

	pt_ct = 0;
	if ((d = pnd[DT][X]))
	{
		p = pnd[P1][X];
		set_mult_pxl_dec(pnd[PND_P1], pnd[PND_DT], (r = -p / d), isect[pt_ct++]);
		r = ((double)(v->w - 1) - p) / d;
		set_mult_dims_arbgs(pnd[P1], pnd[DT], r, isect[pt_ct++]);
	}
	if ((d = pnd[DT][Y]))
	{
		p = pnd[P1][Y];
		set_mult_dims_arbgs(pnd[P1], pnd[DT], (r = -p / d)), isect[pt_ct++]);
		r = ((double)(v->h - 1) - p) / d;
		set_mult_dims_arbgs(pnd[P1], pnd[DT], r, isect[pt_ct++]);
	}
	return (filter_isects(v, pnd, pt_ct, isect));
}
