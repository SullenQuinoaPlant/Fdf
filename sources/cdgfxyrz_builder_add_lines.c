/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdgfxyrz_builder_add_lines.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 04:53:58 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/08 05:34:11 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "scene.h"

#define I 0
#define J 1

static int				add_x_lines(
	t_s_cdgfxyrz *p,
	t_tag *tags,
	t_s_s *s,
	t_list **p_list)
{
	size_t	i;
	size_t	j;
	t_s_l	l;
	t_s_se	*p_e;
	t_list	*p_l;

	p_l = *p_list;
	i = -1;
	while (++i < p->x_sz && !(j = 0))
	{
		l = (t_s_l){1, {tags[i * p->y_sz], 0}, {p->ar[i * p->y_sz], 0}};
		while (++j < p->y_sz)
		{
			if ((get_nxt_se(e_slna, s, p_l->content, &p_e)) != SUCCESS)
				return (SYS_ERR);
			l.ends[0] = l.ends[1];
			l.argb[0] = l.argb[1];
			l.ends[1] = pt_tags[i * p->y_sz + j];
			l.argb[1] = p->ar[i * p->y_sz + j].col;
			*p_e = l;
			p_l = p_l->next;
		}
	}
	*p_list = p_l;
	return (SUCCESS);
}

static int				add_y_lines(
	t_s_cdgfxyrz *p,
	t_tag *tags,
	t_s_s *s,
	t_list **p_list)
{
	size_t	i;
	size_t	j;
	t_s_l	l;
	t_s_se	*p_e;
	t_list	*p_l;

	p_l = *p_list;
	i = -1;
	while (++i < p->y_sz && !(j = 0))
	{
		l = (t_s_l){1, {tags[i], 0}, {p->ar[i], 0}};
		while (++j < p->x_sz)
		{
			if ((get_nxt_se(e_slna, s, p_l->content, &p_e)) != SUCCESS)
				return (SYS_ERR);
			l.ends[0] = l.ends[1];
			l.argb[0] = l.argb[1];
			l.ends[1] = pt_tags[i + p->y_sz * j];
			l.argb[1] = p->ar[i + p->y_sz * j].col;
			*p_e = l;
			p_l = p_l->next;
		}
	}
	*p_list = p_l;
	return (SUCCESS);
}

int						cdgfxyrz_add_lines(
	t_s_cdgfxyrz *p,
	t_tag *tags,
	t_s_s *s,
	t_s_o *o)
{
	t_list	*p_l;

	p_l = o->e[e_ol];
	if (add_x_lines(p, tags, s, &p_l) == SUCCESS &&
		add_y_lines(p, tags, s, &p_l) == SUCCESS)
		return (SUCCESS);
	return (SYS_ERR);
}
