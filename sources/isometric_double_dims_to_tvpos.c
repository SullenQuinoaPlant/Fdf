/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_double_dims_to_tvpos.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 02:57:30 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/13 04:28:37 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_typedefs.h"

int								iso_dbl_dims_to_tvpos(
	t_s_sv *v,
	double pos[DIMS],
	t_vpos ret)
{
	int		r;

	r = dbl_to_tvuint(v->w, pos[X], ret[V_W]);
	r |= dbl_to_tvuint(v->h, pos[Y], ret[V_H]);
}
