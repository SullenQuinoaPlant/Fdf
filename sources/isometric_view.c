/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_view.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 06:16:07 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/15 03:15:59 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

static int				set_prj(
	t_s_sv *v)
{
	t_proj const	ar = {
		
}

int						add_isometric_v(
	t_s_s *s
	t_vuint h,
	t_vuint w)
{
	t_s_sv		*new;
	t_s_pctr	*ct;
	int		r;

	if ((r = add_view(s, &new)) == SUCCESS &&
		(new->ct = add_isometric_camera))
	{
		set_prj(new);
	}





	return (SUCCESS);
}
