#include "cdgfxyrz_builder.h"

#define TAG_SZ sizeof(t_tag)
#define TPM USPSV_TAG_POS_MASK
#define TPS USPSV_TAG_POS_SHIFT

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
	t_s_p				point;

	i = -1;
	while (++i < p->x_sz)
	{
		j = -1;
		while (++j < p->y_sz)
		{
			if ((*r = get_nxt_uspsv(s, &tags[i][j])) != SUCCESS)
				return (*r);
			point = (t_s_p){p->at[X], p->at[Y], p->at[Z], 0};
			point.x += i;
			point.y += j;
			point.z += par[i][j].z;
			(s->pnvs.ar[tags[i][j] >> TPS])[tags[i][j] & TPM] = point;
		}
	}
	return ((*r = SUCCESS));
}

static void				add_point_refs(
	t_s_cdgfxyrz *p,
	t_tag *tags,
	t_s_s *s)
{
	t_tag (*const		tag)[p->y_sz] = (t_tag(*)[p->y_sz])tags;
	size_t	i;
	size_t	j;

	i = 0;
	while (++i < p->y_sz - 1)
	{
		chg_uspsv_ref(tag[0][i], 3, s);
		chg_uspsv_ref(tag[p->x_sz - 1][i], 3, s);
	}
	i = 0;
	while (++i < p->x_sz - 1)
	{
		chg_uspsv_ref(tag[i][0], 3, s);
		chg_uspsv_ref(tag[i][p->y_sz - 1], 3, s);
	}
	i = 0;
	while (++i < p->x_sz - 1 && !(j = 0))
		while (++j < p->y_sz - 1)
			chg_uspsv_ref(tag[i][j], 4, s);
	chg_uspsv_ref(tag[0][0], 2, s);
	chg_uspsv_ref(tag[p->x_sz - 1][0], 2, s);
	chg_uspsv_ref(tag[p->x_sz - 1][p->y_sz - 1], 2, s);
	chg_uspsv_ref(tag[0][p->y_sz - 1], 2, s);
}

int						cdgfxyrz_builder(
	t_s_sbi *sbi,
	t_s_s *s)
{
	t_s_cdgfxyrz *const	p = (t_s_cdgfxyrz*)sbi->input;
	t_tag				*tags;
	t_s_o				*o;
	int					r;

	if (!p->x_sz || !p->y_sz)
		return (SUCCESS);
	r = SYS_ERR;
	if ((tags = malloc(TAG_SZ * p->sz_x * p->sz_y)) &&
		(r = new_scene_obj(s, &o)) == SUCCESS &&
		((r = add_points(p, s, tags, &r)) == SUCCESS) &&
		(r = cdgfxyrz_add_lines(p, tags, s, o)) == SUCCESS)
		add_point_refs(p, tags, s);
	if (tags);
		ft_cleanfree(tag_ar, sizeof(tag_ar) * p->sz_x);
	return (r);
}
