/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 04:52:56 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/15 08:00:41 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "scene.h"

int						nxt_fresh_obj(
	t_s_s *s,
	t_s_o **ret,
	t_tag *ret_tag)
{
	t_tag	tag;
	t_s_o	*o;
	int		r;

	*ret = 0;
	if ((r = get_nxt_se(e_so, s, &tag, (void**)&o)) != SUCCESS)
		return (r);
	ft_bzero(o, sizeof(t_s_o));
	o->hdl.type = e_seg_null;
	if (ret_tag)
		*ret_tag = tag;
	*ret = o;
	return (r);
}

int						nxt_active_obj(
	t_s_s *s,
	t_s_o **ret,
	t_tag *ret_tag)
{
	int		r;

	if ((r = nxt_fresh_obj(s, ret, ret_tag)) == SUCCESS &&
		(r = ring_expand(sizeof(t_s_ao), 0, (void**)&s->ao) == RING_SUCCESS))
	{
		(**ret).refs = 1;
		(**ret).flgs |= O_SHOW;
	}
	return (r);
}
