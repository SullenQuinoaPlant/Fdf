/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdgfxyrz_builder_add_lines.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 04:53:58 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/18 12:11:55 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "scene.h"
#include "parse.h"

static int				add_y_lines(
	t_s_cdgfxyrz *p,
	t_tag *tags,
	t_s_s *s,
	t_list **p_l)
{
	t_tag (*const	tar)[p->y_sz] = (t_tag(*)[p->y_sz])tags;
	size_t			i;
	size_t			j;
	t_s_l			l;
	t_s_l			*p_e;

	i = -1;
	while (++i < p->x_sz)
	{
		j = 0;
		l = (t_s_l){1, {0, tar[i][0]}, {0, p->ar[i * p->y_sz].col}};
		while (++j < p->y_sz)
		{
			if (ft_lstaddnew(p_l, (t_tag[1]){0}, sizeof(t_tag)) ||
				get_nxt_se(e_l, s, (**p_l).content, (void**)&p_e) != SUCCESS)
				return (SYS_ERR);
			l.ends[0] = l.ends[1];
			l.argb[0] = l.argb[1];
			l.ends[1] = tar[i][j];
			l.argb[1] = p->ar[p->y_sz * i + j].col;
			*p_e = l;
		}
	}
	return (SUCCESS);
}

static int				add_x_lines(
	t_s_cdgfxyrz *p,
	t_tag *tags,
	t_s_s *s,
	t_list **p_l)
{
	t_tag (*const	tar)[p->y_sz] = (t_tag(*)[p->y_sz])tags;
	size_t			i;
	size_t			j;
	t_s_l			l;
	t_s_l			*p_e;

	i = -1;
	while (++i < p->y_sz)
	{
		j = 0;
		l = (t_s_l){1, {0, tags[i]}, {0, p->ar[i].col}};
		while (++j < p->x_sz)
		{
			if (ft_lstaddnew(p_l, (t_tag[1]){0}, sizeof(t_tag)) ||
				get_nxt_se(e_l, s, (**p_l).content, (void**)&p_e) != SUCCESS)
				return (SYS_ERR);
			l.ends[0] = l.ends[1];
			l.argb[0] = l.argb[1];
			l.ends[1] = tar[j][i];
			l.argb[1] = p->ar[p->y_sz * j + i].col;
			*p_e = l;
		}
	}
	return (SUCCESS);
}

int						cdgfxyrz_add_lines(
	t_s_cdgfxyrz *p,
	t_tag *tags,
	t_s_s *s,
	t_s_o *o)
{
	if (add_x_lines(p, tags, s, &o->e[e_l]) == SUCCESS &&
		add_y_lines(p, tags, s, &o->e[e_l]) == SUCCESS)
		return (SUCCESS);
	return (SYS_ERR);
}
