/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdgfxyrz_builder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 04:54:31 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/07 05:03:34 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cdgfxyrz_builder.h"

/*
**LINE_COUNT  is :
**(x_sz - 1) * y_sz + (y_sz - 1) * x_sz
*/
static int				get_container_obj(
	t_s_cdgfxyrz *p,
	t_s_s *s,
	t_s_o **o)
{
	t_list			*tl;
	t_list			*lines;
	size_t			l_ct;
	int				r;

	*o = 0;
	l_ct = (p->x_sz - 1) * p->y_sz + (p->y_sz - 1) * p->x_sz;
	lines = 0;
	if ((r = nxt_active_obj(s, o, 0)) == SUCCESS)
		while (l_ct && (tl = ft_lstnew(&((t_tag[1]){0}), sizeof(t_tag))
		{
			ft_lstadd(&lines, tl);
			l_ct--;
		}
	if (l_ct)
	{
		r = SYS_ERR;
		ft_lstdel(&lines, 0);
	}
	else
		(**o).e[e_ol] = lines;
	return (r);
}

/*
**Put int *r in the argument list because of 5 var limit and an aversion
**	to ij[2] arrays and SZ * ij[I] + ij[J] arithmetic.
*/
static int					add_points(
	t_s_cdgfxyrz *p,
	t_s_s *s,
	t_tag *ts,
	int *r)
{
	t_s_cxyd (*const	par)[p->y_sz][1] = (t_s_cxyd(*)[p->y_sz][1])p->ar;
	t_tag (*const		tags)[p->y_sz] = (t_tag(*)[p->y_sz])ts;
	size_t				i;
	size_t				j;
	t_s_p				*pt;

	i = -1;
	while (++i < p->x_sz)
	{
		j = -1;
		while (++j < p->y_sz)
		{
			if ((*r = get_nxt_se(s, e_spnv, &tags[i][j])) != SUCCESS)
				return (*r);
			pt = &(s->es[e_spnv].ar[tags[i][j] >> TPS])[tags[i][j] & TPM];
			pt->xyz[X] = i + p->at[X];
			pt->xyz[Y] = j + p->at[Y];
			pt->xyz[Z] = par[i][j].z + p->at[Z];
		}
	}
	return ((*r = SUCCESS));
}

static void				add_point_refct(
	t_s_cdgfxyrz *p,
	t_tag *tags,
	t_s_s *s)
{
	t_tag (*const		tar)[p->y_sz] = (t_tag(*)[p->y_sz])tags;
	t_s_se *const		grp = &s->e[e_spnv];
	size_t				i;
	size_t				j;

	i = 0;
	while (++i < p->y_sz - 1)
	{
		chg_tag_refct(tar[0][i], 3, grp);
		chg_tag_refct(tar[p->x_sz - 1][i], 3, grp);
	}
	i = 0;
	while (++i < p->x_sz - 1)
	{
		chg_tag_refct(tar[i][0], 3, grp);
		chg_tag_refct(tar[i][p->y_sz - 1], 3, grp);
	}
	i = 0;
	while (++i < p->x_sz - 1 && !(j = 0))
		while (++j < p->y_sz - 1)
			chg_tag_refct(tar[i][j], 4, grp);
	chg_tag_refct(tar[0][0], 2, grp);
	chg_tag_refct(tar[p->x_sz - 1][0], 2, grp);
	chg_tag_refct(tar[p->x_sz - 1][p->y_sz - 1], 2, grp);
	chg_tag_refct(tar[0][p->y_sz - 1], 2, grp);
}

int						cdgfxyrz_builder(
	t_s_sbi *sbi,
	t_s_s *s)
{
	t_s_cdgfxyrz *const	p = (t_s_cdgfxyrz*)sbi->input;
	size_t const		sz = TAG_SZ * p->sz_x * p->sz_y;
	t_tag				*tags;
	t_s_o				*o;
	int					r;

	if (!p->x_sz || !p->y_sz)
		return (SUCCESS);
	r = SYS_ERR;
	if ((tags = malloc(sz)) &&
		(r = get_container_obj(p, s, &o)) == SUCCESS &&
		(r = add_points(p, s, tags, &r)) == SUCCESS &&
		(r = cdgfxyrz_add_lines(p, tags, s, o)) == SUCCESS)
		add_point_refct(p, tags, s);
	if (tags);
		ft_cleanfree(tags, sz);
	return (r);
}
