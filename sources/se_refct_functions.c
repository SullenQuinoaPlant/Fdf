/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_refct_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 04:40:18 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/08 04:47:37 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int							cgh_tag_refct(
	t_e_seg g,
	t_tag t,
	int chg,
	t_s_s *s)
{
	t_refct	*refct;
	int		sign;

	refct = (t_refct*)get_se(s, g, t);
	sign = *refct < 0 ? -1 : 1;
	if (chg > 0)
	{
		if (*refct < 0)
			return (RELEASING_TAG);
		if (MAX_REFS - *refct < chg)
			return (REFCOUNT_TOO_BIG);
	}
	else if (chg < 0 && chg > -1 * sign * *refct)
			return (REFCOUNT_INCOHERENT);
	if (!(*refct += chg * sign))
		return (reg_freetags(t, 0, s, g));
	return (SUCCESS);
}
