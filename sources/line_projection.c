/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_projection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 20:53:53 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/12 03:20:18 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_typedefs.h"
#include "scene.h"


static int						all_visible(
	t_s_sv *v,
	double (*r)[DIMS + ARGBS])
{
	if (is_visible(v->w, v->h, r[P1]) && is_visible(v->w, v->h, r[P1]))
		return (1);
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
	double			pnd[3][DIMS + ARGBS]
	int				count;

	set_someof_pnd(loa, pts, pnd);
	if (!all_visible(v, loa, pts, ret))
	{
		set_somemoreof_pnd(loa, pnd);
		get_intersections(v, pnd);
	}
	set_ret(pnd, ret);
}
