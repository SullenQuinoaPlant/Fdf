#include "parsed.h"
#include "scene.h"

#define I 0
#define J 1

static int				add_most_lines(
	t_s_cdgfxyrz *p,
	t_tag *tags,
	t_s_s *s,
	t_s_o *o)
{
	size_t	ij[2];
	t_s_l	l;
	t_tag	tag[2];
	t_list	*p;
	int		r;

	i = 0;
	l.refs = 1;
	pl = o->e[e_ol];
	r = SUCCESS;
	while (++i < p->x_sz && !(j = 0) && r == SUCCESS)
		while ((r = get_nxt_se(e_slna, s, &tag[0], 0)) == SUCCESS &&
			(r = get_nxt_se(e_slna, s, &tag[1], 0)) == SUCESS && ++j < p->y_sz)
		{
			l.ends[0] = tags[i * p->y_sz + j];
			l.argb[0] = p->ar[i * p->y_sz + j].col;
			l.ends[1] = tags[i * p->y_sz + j - 1];
			l.argb[1] = p->ar[i * p->y_sz + j - 1].col;
			(s->lnas.ar[tag[0] >> TPS])[tag[0] & TPM] = l;
			ft_memcpy(p->content, &tag[0], sizeof(t_tag));
			l.ends[1] = tags[(i - 1) * p->y_sz + j];
			l.argb[1] = p->ar[(i - 1) * p->y_sz + j].col;
			(s->lnas.ar[tag[1] >> TPS])[tag[1] & TPM] = l;
			ft_memcpu((p = p->next)->content, &tag[1], sizeof(t_tag));
			p = p->next;
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
