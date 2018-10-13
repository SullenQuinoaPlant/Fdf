/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubles_to_tvpos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 03:26:50 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/13 02:56:44 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_typedefs.h"

void							doubles_to_tvpos(
	t_s_sv *v,
	double coords[DIMS],
	t_vpos *ret)
{
	int		i;

	i = -1;
	while (++i < V_DIMS)
		ret[i] = (t_vuint)coords[i];
}
