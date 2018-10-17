/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_line_projection.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 20:53:53 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/15 08:44:32 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "scene.h"
#include "line_frame_intersections.h"

static int						count_visibles(
	t_s_sv *v,
	t_pdp pdp)
{
	double	tmp[PXL_DEC_SZ];

	if (is_iso_visible(v, pdp[PDP_P1]))
	{
		if (is_iso_visible(v, pdp[PDP_P2]))
			return (2);
		else
		{
			ft_memswap(&pdp[PDP_P1], &pdp[PDP_P2], tmp);
			return (1);
		}
	}
	return (0);
}

static void					 	set_someof_pdp(
	t_s_l *l,
	t_s_p const *const *pts,
	t_pdp pdp)
{
	size_t const	dims_sz = sizeof(double) * DIMS;
	t_tag			t;

	t = l->ends[0];
	ft_memcpy(pdp[PDP_P1], &(pts[t >> TPS])[t & TPM], dims_sz);
	t = l->ends[1];
	ft_memcpy(pdp[PDP_P2], &(pts[t >> TPS])[t & TPM], dims_sz);
}

static void						set_somemoreof_pdp(
	t_s_l *l,
	t_pdp pdp)
{
	int		i;

	targb_to_doubles(l->argb[0], pdp[PDP_P1] + PDAO);
	targb_to_doubles(l->argb[1], pdp[PDP_P2] + PDAO);
	i = -1;
	while (++i < PXL_DEC_SZ)
		pdp[PDP_DT][i] = pdp[PDP_P2][i] - pdp[PDP_P1][i];
}

stati void						set_ret(
	t_s_sv *v,
	t_dpd pdp,
	t_s_lp *ret)
{
	iso_dbl_dims_to_tvpos(v, pdp[PDP_P1], ret->ends[0]);
	iso_dbl_dims_to_tvpos(v, pdn[PDP_P2], ret->ends[1]);
	doubles_to_targb(&pdp[PDP_P1][PDAO], &ret->argb[0]);
	doubles_to_targb(&pdp[PDP_P2][PDAO], &ret->argb[1]);
	ret->prec[0] = pdp[PDP_P1][Z];
	ret->prec[1] = pdp[PDP_P2][Z];
}

/*
** The 'pdp' array holds the coordinates, and the color values of
** P1, P2 and the delta vector (P2 - P1).
** See .h for indexes.
*/
void							isometric_line_proj(
	t_s_sv *v,
	void *line,
	t_s_p const *const *pts,
	void *ret_tslp)
{
	t_s_l *const	l = (t_s_l*)line;
	t_s_lp *const	ret = (t_s_lp*)ret_tslp;
	t_pdp			pdp;

	set_someof_pdp(l, pts, pdp);
	l->flgs |= F_V_VISIBLE;
	if (count_visibles(v, l, pts, ret) < 2)
	{
		set_somemoreof_pdp(l, pdp);
		if (isometric_line_xy_isect(v, pdp) == OUT_OF_VIEW ||
			isometric_line_z_isect(pdp) == OUT_OF_VIEW)
			loa->flgs &= ~F_V_VISIBLE;
	}
	set_ret(pdp, ret);
}
