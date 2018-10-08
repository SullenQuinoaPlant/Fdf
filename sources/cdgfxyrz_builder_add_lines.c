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

	l = (t_s_l){1, {tags[0], 0}, {p->ar[0], 0}};
	p_l = *p_list;
	i = -1;
	while (++i < p->x_sz && !(p = 0))
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

	l = (t_s_l){1, {tags[0], 0}, {p->ar[0], 0}};
	p_l = *p_list;
	i = -1;
	while (++i < p->x_sz && !(j = 0))
		while (++j < p->y_sz)
		
			if ((get_nxt_se(e_slna, s, p_l->content, &p_e)) != SUCCESS)
				return (SYS_ERR);
			l.ends[0] = l.ends[1];
			l.argb[0] = l.argb[1];
			l.ends[1] = pt_tags[i * p->y_sz + j];
			l.argb[1] = p->ar[i * p->y_sz + j].col;
			*p_e = l;
			p_l = p_l->next;
		}
	*p_list = p_l;
	return (SUCCESS);
}

static int				add_y0_edge_lines(
	t_s_cdgfxyrz *p,
	t_tag *tags,
	t_s_s *s,
	t_s_o *o)
{
	size_t	i;
	size_t	j;
	t_s_l	l;
	t_tag	tag;
	int		r;

	r = SUCCESS;
	l.refs = 1;
	i = -1;
	while (++i < p->y_sz - 1 &&
		(r = get_nxt_se(e_slna, s, &tag, 0)) != SUCCESS))
	{
		j = i + 1;
		l.ends = (t_tag[2]){tags[i], tags[j]};
		l.argb = (t_argb[2]){p->ar[i].col, p->ar[j].col};
		(s->lnas.ar[tag[0] >> TPS])[tag[0] & TPM] = l;
		o->lnas[o->lnas.count++] = tag;
	}
	return (r);
}

static int				add_x0_edge_lines(
	t_s_cdgfxyrz *p,
	t_tag *tags,
	t_s_s *s,
	t_s_o *o)
{
	size_t	i;
	size_t	j;
	t_s_l	l;
	t_tag	tag;
	int		r;

	l.refs = 1;
	i = 0;
	r = SUCCESS;
	while (i < (p->x_sz - 1) * p->y_sz &&
		(r = get_nxt_uslsa(e_slna, s, &tag, 0) != SUCCESS))
	{
		j = i + p->y_sz;
		l.ends = (t_tag[2]){tags[i], tags[j]};
		l.argb = (t_argb[2]){p->ar[i].col, p->ar[j].col};
		(s->lnas.ar[tag[0] >> TPS])[tag[0] & TPM] = l;
		o->lnas[o->lnas.count++] = tag;
	}
	return (r);
}

int						cdgfxyrz_add_lines(
	t_s_cdgfxyrz *p,
	t_tag *tags,
	t_s_s *s,
	t_s_o *o)
{
	int		r;

	if ((r = add_most_lines(p, tags, s, o)) == SUCCESS &&
		(r = add_x0_edge_lines(p, tags, s, o)) == SUCCESS &&
		(r = add_y0_edge_lines(p, tags, s, o)) == SUCCESS)
		;
	return (r);
}
