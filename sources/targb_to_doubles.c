/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targb_to_doubles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 01:57:03 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/12 02:22:17 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_typedefs.h"
#include "scene.h"

void							targb_to_doubles(
	t_argb argb,
	double ret[ARGBS])
{
	int		i;

	i = ARGBS;
	while (--i)
	{
		ret[i] = argb & ARGB_MASK;
		argb >> ARGB_BYTE;
	}
}

/*
**No special fancy rounding, just a cast and a mask.
*/
void							doubles_to_targb(
	double argb[ARGBS],
	t_argb *ret)
{
	int		i;
	t_argb	argb;

	i = -1;
	while (++i < ARGBS)
	{
		argb << ARGB_BYTE;
		argb |= ((t_argb)*argb++) & ARGB_MASK;
	}
	*ret = argb;
}
