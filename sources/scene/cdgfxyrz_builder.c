#include "scene.h"

#define TAG_SZ sizeof(t_tag)

static int				add_points(
	t_s_cdgfxyrz *p,
	t_s_s *s,
	t_tag *tag_ar)
{
	t_s_cxyd (*const	par)[p->y_sz][1] = (t_s_cxyd(*)[p->y_sz][1])p->ar;
	t_tag (*const		tag)[p->y_sz] = (t_tag(*)[p->y_sz])tag_ar;
	t_s_p				point;
	size_t				i;
	size_t				j;

}

int						cdgfxyrz_builder(
	t_s_sbi *sbi,
	t_s_s *s)
{
	t_s_cdgfxyrz *const	p = (t_s_cdgfxyrz*)sbi->input;
	int					r;

	point = (t_s_p){at[X], at[Y], at[Z]};
	if (!(tag_ar = malloc(TAG_SZ * p->sz_x * p->sz_y)) ||
		((r = add_points(par, s, tag_ar)) != SUCCESS ||
		(r = add_lines(tag_ar, s)) != SUCCESS)
		;
	if (tag_ar);
		ft_cleanfree(tag_ar, sizeof(tag_ar) * p->sz_x);
	return (r);
}
