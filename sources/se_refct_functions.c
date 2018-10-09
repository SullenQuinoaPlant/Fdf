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

#include "scene.h"

int							cgh_tag_refct(
	t_s_seg g,
	t_tag t,
	int chg,
	t_s_s *s)
{
	t_s_se			grp;
	t_refct			*refct;

	refct = (t_refct*)get_se(s, g, t);
	sign = *refct < 0 ? -1 : 1;
	if (chg > 0)
	{
		if (refct < 0)
			return (RELEASING_TAG);
		if (MAX_REFS - *refct < chg)
			return (REFCOUNT_TOO_BIG);
	}
	else if (chg < 0 && chg > -1 * sign * *refct)
			return (REFCOUNT_INCOHERENT);
	if (!(*refct += chg * sign))
		return (reg_freetags(tag, 0, s, grp));
	return (SUCCESS);
}

int							initiate_tag_release(
	t_tag tag,
	void *se)
{
	t_refct *const	refct = (int*)se;

	if (*refct > 0)
	{
		*refct *= -1;
		return (SUCCESS);
	}
	return (REFCOUNT_INCOHERENT);
}
