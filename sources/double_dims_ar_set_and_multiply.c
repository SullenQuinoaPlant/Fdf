/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_dims_ar_set_and_multiply.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 23:21:23 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/12 23:33:40 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "outer.h"

void						sem_mult_dims_argb(
	double src[DIMS],
	double deltas[DIMS],
	double ratio,
	double dest[DIMS])
{
	int		i;

	ft_memcpy(dest, src, sizeof(double) * DIMS);
	int = -1;
	while (++i < DIMS + ARGBS)
		dest[i] += ratio * deltas[i];;
}

void						set_mult_dims(
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
