/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tsso_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 04:52:56 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/18 11:25:43 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "scene.h"

static int				nxt_fresh_obj(
	t_s_s *s,
	t_s_o **ret,
	t_tag *ret_tag)
{
	t_tag	tag;
	t_s_o	*o;
	int		r;

	if ((r = get_nxt_se(e_o, s, &tag, (void**)&o)) != SUCCESS)
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

	*ret = 0;
	if (ret_tag)
		*ret_tag = 0;
	if (!ring_expand(sizeof(t_s_ao), 0, (void**)&s->ao))
		return (SYS_ERR);
	if ((r = nxt_fresh_obj(s, ret, ret_tag)) == SUCCESS)
	{
		(**ret).refs = 1;
		(**ret).flgs |= O_SHOW;
	}
	else
		ring_shrink(sizeof(t_s_ao), ft_free, (void**)&s->ao);
	return (r);
}

void					free_object_lists(
	t_s_o *o)
{
	t_e_seg		i;

	i = e_p;
	while (i < e_seg_sz)
		ft_lstdel(&o->e[i++], ft_free);
}
