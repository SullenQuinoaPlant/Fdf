#include "cdgfxyrz_builder.h"

#define TPM USPSV_TAG_POS_MASK
#define TPS USPSV_TAG_POS_SHIFT

static int				add_most_lines(
	t_s_cdgfxyrz *p,
	t_tag *tags,
	t_s_s *s,
	t_s_o *o)
{
	size_t	i;
	size_t	j;
	t_s_l	l;
	t_tag	tag[2];
	int		r;

	i = 0;
	r = SUCCESS;
	while (++i < p->x_sz && !(j = 0) && r == SUCCESS)
		while (++j < p->y_sz && (r = get_nxt_uslsa(s, &tag[0])) == SUCCESS &&
			(r = get_nxt_uslsa(s, &tag[1])) == SUCCESS)
		{
			l.ends[0] = tags[i * p->y_sz + j];
			l.rgba[0] = p->ar[i * p->y_sz + j].col;
			l.refs = 1;
			l.ends[1] = tags[i * p->y_sz + j - 1];
			l.rgba[1] = p->ar[i * p->y_sz + j - 1].col;
			(s->lnas.ar[tag[0] >> TPS])[tag[0] & TPM] = l;
			o->lnas.ar[++o->lnas.count] = tag[0];
			l.ends[1] = tags[(i - 1) * p->y_sz + j];
			l.rgba[1] = p->ar[(i - 1) * p->y_sz + j].col;
			(s->lnas.ar[tag[1] >> TPS])[tag[1] & TPM] = l;
			o->lnas.ar[++o->lnas.count] = tag[1];
		}
	return (r);
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
	while (++i < p->y_sz - 1 && (j = i + 1) &&
		(r = get_nxt_uslsa(s, &tag) != SUCCESS))
	{
		l.ends = (t_tag[2]){tags[i], tags[j];
		l.rgba = (t_rgba[2]){p->ar[i].col, p->ar[j]};
		(s->lnas.ar[tag[0] >> TPS])[tag[0] & TPM] = l;
		o->lnas[++o->lnas.count] = tag;
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
	while (i < (p->x_sz - 1) * p->y_sz && (j = i + p->y_sz) &&
		(r = get_nxt_uslsa(s, &tag) != SUCCESS))
	{
		l.ends = (t_tag[2]){tags[i], tags[j];
		l.rgba = (t_rgba[2]){p->ar[i].col, p->ar[j]};
		(s->lnas.ar[tag[0] >> TPS])[tag[0] & TPM] = l;
		o->lnas[++o->lnas.count] = tag;
	}
	return (r);
}

int						cdgfxyrz_add_lines(
	t_s_cdgfxyrz *p,
	t_tag *tags,
	t_s_s *s,
	t_s_o *o)
{
	t_line_adder const	fs[3] =
	{
		add_most_lines,
		add_y0_edge_lines,
		add_x0_edge_lines
	};
	int		r;
	int		i;

	i = 0;
	while ((r = *fs[i](p, tags, s, o)) == SUCCESS)
		i++;
	return (r);
}
