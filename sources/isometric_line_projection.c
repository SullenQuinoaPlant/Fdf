/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_line_projection.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 20:53:53 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/18 17:20:17 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "scene.h"
#include "line_frame_intersections.h"

static int						count_visibles(
	t_s_sv *v,
	t_pdp pdp,
	int *p1_is_visible)
{
	if (is_iso_visible(v, pdp[PDP_P1]))
	{
		*p1_is_visible = 1;
		if (is_iso_visible(v, pdp[PDP_P1]))
			return (2);
		else
			return (1);
	}
	*p1_is_visible = 0;
	return (0);
}

static void					 	set_someof_pdp(
	t_s_l *l,
	t_s_pp const *const *pts,
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

	targb_to_doubles(l->argb[0], pdp[PDP_P1] + PTDAO);
	targb_to_doubles(l->argb[1], pdp[PDP_P2] + PTDAO);
	i = -1;
	while (++i < PNT_DEC_SZ)
		pdp[PDP_DT][i] = pdp[PDP_P2][i] - pdp[PDP_P1][i];
}

static void						set_ret(
	t_s_sv *v,
	t_pdp pdp,
	int count,
	t_s_lp *ret)
{
	iso_dbl_dims_to_tvpos(v, pdp[PDP_P1], ret->ends[0]);
	iso_dbl_dims_to_tvpos(v, pdp[PDP_P2], ret->ends[1]);
	if (count < 2)
	{
		doubles_to_targb(&pdp[PDP_P2][PTDAO], &ret->argb[1]);
		if (!count)
			doubles_to_targb(&pdp[PDP_P1][PTDAO], &ret->argb[0]);
	}
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
	t_s_pp const *const *pts,
	void *ret_tslp)
{
	t_s_l *const	l = (t_s_l*)line;
	t_s_lp *const	ret = (t_s_lp*)ret_tslp;
	t_pdp			pdp;
	int				count;
	int				p1_is_vis;

	set_someof_pdp(l, pts, pdp);
	ret->flgs |= F_V_VISIBLE;
	if ((count = count_visibles(v, pdp, &p1_is_vis)) < 2)
	{
		set_somemoreof_pdp(l, pdp);
		if (!p1_is_vis)
		{
			ft_memswap(pdp[PDP_P1], pdp[PDP_P2], sizeof(t_pdd));
			mult_dbl_ar(-1, PNT_DEC_SZ, pdp[PDP_DT]);
		}
		if (isometric_line_xy_isect(v, pdp) == OUT_OF_VIEW ||
			isometric_line_z_isect(pdp) == OUT_OF_VIEW)
			ret->flgs &= ~F_V_VISIBLE;
	}
	else
		ft_memcpy(ret->argb, l->argb, sizeof(t_argb[2]));
	set_ret(v, pdp, count, ret);
}
