/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_projection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 20:53:53 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/12 01:56:21 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_typedefs.h"
#include "scene.h"

static int						is_visible(
	t_vuint w,
	t_vuint h,

static int						all_visible(
	t_s_sv *v,
	t_u_slsa *loa,
	t_u_spsv const *pts,
	double (*ret)[DIMS + ARGBS];
	t_s_loap *ret)
{
	double	(*coords)[DIMS];
	t_tag	t;

	ft_memcpy(ret, &(pts[(t = loa->ends[0]) >> TPS])[t & TPM], DBL_DIMS_SZ);
	ft_memcpy(ret, &(pts[(t = loa->ends[1]) >> TPS])[t & TPM], DBL_DIMS_SZ);
	if (

}

static void					 	set_pnv_count_visible(
	t_s_sv *v,
	t_u_slsa *loa,
	t_u_spsv const *const *pts,
	double (*ret)[DIMS + ARGBS])
{
	t_tag	t;

	if (is_visible(pts[(t = loa->ends[1]) >> TPS] 
	ft_memcpy(ret, (pts[(t = loa->ends[1]) >> TPS])[t & TPM].xyz, sizeof());
	p = (pts[(t = loa->ends[1]) >> TPS])[t & TPM].xyz;
	i = -1;
	while (++i < DIMS)
		dlt[i] -= p[i];
	i = 0;
}

static void

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

	if (!all_visible(loa, ret)
	{
		fill_pnd(v, loa, pts, pnd);
		get_intersections(v, pnd);
	}
	set_ret(pnd, ret);
}
