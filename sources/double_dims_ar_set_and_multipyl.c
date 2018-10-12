/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_dims_ar_set_and_multipyl.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 23:21:23 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/12 23:25:56 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "outer.h"

static void						set_and_mult_dims_ar(
	double src[DIMS],
	double deltas[DIMS],
	double ratio,
	double dest[DIMS])
{
	int		i;

	ft_memcpy(dest, src, sizeof(double) * DIMS);
	int = -1;
	while (++i < DIMS)
		dest[i] += ratio * deltas[i];;
}
