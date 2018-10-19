/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_view_double_tvuint_conversions.c         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 03:30:50 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/13 04:28:07 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "scene.h"

int								iso_dbl_to_tvuint(
	t_vuint const dim_sz,
	double const d,
	t_vuint *ret)
{
	int const		sign = d > 0 ? 1 : -1;
	t_vuint const	offset = dim_sz / 2;

	if (!iso_dbl_within_dimsz(dim_sz, d))
		return (OUT_OF_VIEW);
	if (sign == 1)
		*ret = (t_vuint)d + offset;
	else
		*ret = offset - (t_vuint)(sign * d);
	return (SUCCESS);
}

int								iso_dbl_dims_to_tvpos(
	t_s_sv const *v,
	double const pos[DIMS],
	t_vpos ret)
{
	int		r;

	r = iso_dbl_to_tvuint(v->w, pos[X], &ret[V_W]);
	r |= iso_dbl_to_tvuint(v->h, pos[Y], &ret[V_H]);
	return (r);
}
