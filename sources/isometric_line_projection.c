/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_line_projection.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 20:53:53 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/13 01:09:03 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_typedefs.h"
#include "scene.h"
#include "line_isometric_view_intersections.h"


static int						count_visible(
	t_s_sv *v,
	double (*pnd)[DIMS + ARGBS])
{
	if (is_visible(v, pnd[P1]))
	{
		if (is_visible(v, pnd[P2]))
			return (2);
		else
		{
			ft_memswap(&r[P1], &r[P2], &r[DT]);
			return (1);
		}
	}
	return (0);
}

static void					 	set_someof_pnd(
	t_u_slsa *loa,
	t_u_spsv const *const *pts,
	double (*r)[DIMS + ARGBS])
{
	t_tag	t;

	ft_memcpy(&r[P1], &(pts[(t = loa->ends[0]) >> TPS])[t & TPM], DBL_DIMS_SZ);
	ft_memcpy(&r[P2], &(pts[(t = loa->ends[1]) >> TPS])[t & TPM], DBL_DIMS_SZ);
}

static void						set_somemoreof_pnd(
	t_u_slsa *loa,
	double (*r)[DIMS + ARGBS])
{
	int		i;

	targb_to_doubles(loa->argb[0], r[P1] + ARGB_OFFSET);
	targb_to_doubles(loa->argb[1], r[P2] + ARGB_OFFSET);
	i = -1;
	while (++i < DIMS + ARGBS)
		r[DT][i] = r[P2][i] - r[P1][i];
}

stati void						set_ret(
	double (*pnd)[DIMS + ARGBS],
	t_s_loap *ret)
{
	doubles_to_tvpos(pnd, &ret->ends[0]);
	doubles_to_tvpos(&pnd[P2], &ret->ends[1]);
	doubles_to_targb(&pnd[P1][ARGB_OFFSET], &ret->argb[0]);
	doubles_to_targb(&pnd[P2][ARGB_OFFSET], &ret->argb[1]);
	ret->prec[0] = pnd[P1][Z];
	ret->prec[1] = pnd[P2][Z];
}

/*
 * The 'pnd' array holds the coordinates, and the color values of,
 * P1, P2 and the delta vector (P2 - P1).
 * See .h for indexes.
*/
void							isometric_loa_proj(
	t_s_sv *v,
	void *line_or_arrow,
	t_u_spsv const *const *pts,
	void *ret_tsloap)
{
	t_u_slsa *const	loa = (t_u_slsa*)line_or_arrow;
	t_s_loap *const	ret = (t_s_loap*)ret_tsloap;
	double			pnd[3][DIMS + ARGBS]

	set_someof_pnd(loa, pts, pnd);
	if (count_visible(v, loa, pts, ret) == 2)
	else
	{
		set_somemoreof_pnd(loa, pnd);
		if (isometric_line_xy_isect(v, pnd, ret.ends))
			isometric_line_z_isect(pnd);
	}
	set_ret(pnd, ret);
}
