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
	size_t const	l_ct = (p->x_sz - 1) * p->y_sz + (p->y_sz - 1) * p->x_sz;
	int				r;

	*o = 0;
	if ((r = nxt_active_obj(s, o, 0)) != SUCCESS ||
		!(o->es[e_slna].ar = malloc(l_ct * TAG_SZ) ||
		return (r != SUCCESS ? r : SYS_ERR);
	o->es[e_slna].count = 0;
	o->es[e_slna].sz = l_ct;
	return (r);
}

static void				add_point_refct(
	t_s_cdgfxyrz *p,
	t_tag *tags,
	t_s_s *s)
{
	t_tag (*const		tar)[p->y_sz] = (t_tag(*)[p->y_sz])tags;
	t_s_se *const		grp = &s->es[e_spnv]
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
			pt.xyz[X] = i + p->at[X];
			pt.xyz[Y] = j + p->at[Y];
			pt.xyz[Z] = par->z + p->at[Z];
		}
	}
	return ((*r = SUCCESS));
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
