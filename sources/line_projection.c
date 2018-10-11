/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_projection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 20:53:53 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/12 01:18:11 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_typedefs.h"
#include "scene.h"

/*
** If there is only one visible point, that point must be placed at position
** 0 in the returned array.
*/ 
static int						visible_points(
	t_s_sv *v,
	t_u_slsa *loa,
	double (*ret)[DIMS])
{
}

/*
 * The 'pnd' array holds the coordinates, and the color values of,
 * P1, P2 and the delta vector (P2 - P1).
 * See .h for indexes.
*/
void							loa_proj(
	t_s_sv *v,
	void *line_or_arrow,
	t_u_spsv const *const *pts,
	void *tsloap)
{
	t_u_slsa *const	loa = (t_u_slsa*)line_or_arrow;
	t_s_loap *const	ret = (t_s_loap*)tsloap;
	double			pnv[DIMS + 1]
	int				count;

	count = visible_points(v, loa, pts, );
	if (count != 2)
	{
		get_intersections(
	}
		count = get_intersections(v, loa, pts, ret->ends);
	filter_zaxis(v, ret);
}
