#include "functions.h"
#include "parse.h"

#define BUF_CT 256
#define BUF_SZ BUF_CT * sizeof(t_s_cxyd)
#define E_CT 0
#define E_CT_ALLOCS 1
static int					new_buff(
	t_list **prv,
	size_t *counters,
	t_s_cxyd **p)
{
	t_list		*new;
	t_s_cxyd	*ar;

	new = 0;
	if ((ar = malloc(BUF_SZ)) &&
		(new = ft_lstnew(0, 0)))
	{
		*p = ar;
		new->content = ar;
		new->content_size = BUF_SZ;
		ft_lstadd(prv, new);
		counters[E_CT] = BUF_CT;
		counters[E_CT_ALLOCS]++;
	}
	else if (ar)
		free(ar);
	return (new ? SUCCESS : SYS_ERR);
}

#define NOT_DONE 1
static int					parse_sncnl_like_really(
	char const **str,
	t_s_cxyd **p)
{
	char const	*s = *str;
	t_argb		col;
	int			z;

	col = 0;
	if (!*s)
		return (SUCCESS);
	if (ft_atoierr(s, &z, (char**)&s) ||
		(*s == ',' && ft_axtoierr(++s, (int*)&col, (char**)&s)) ||
		(*s && *s++ != ' '))
		return (BAD_INFILE);
	*((*p)++) = (t_s_cxyd){z, col};
	return (NOT_DONE);
}

/*
**Constants to access rows and columns:
*/
#define DIM_R 0
#define DIM_C 1
int							parse_cdgfxyrz_sncnl(
	int fd,
	size_t *dims,
	t_list **bs)
{
	char const	*l[2];
	size_t		l_ct;
	size_t		e_ct[2];
	t_s_cxyd	*p;
	int			r;

	*bs = 0;
	l_ct = 0;
	ft_memset(e_ct, 0, 2);
	r = 0;
	while ((r = get_next_line(fd, (char**)&l[0])) > 0)
	{
		l[1] = l[0];
		l_ct++;
		while ((e_ct[E_CT] || (r = new_buff(bs, e_ct, &p)) == SUCCESS) &&
			(r = parse_sncnl_like_really(&l[1], &p) == SUCCESS))
			e_ct[E_CT]--;
		free((void*)l[0]);
		if (r != SUCCESS)
			return (r);
	}
	dims[DIM_R] = l_ct;
	dims[DIM_C] = (e_ct[E_CT_ALLOCS] * BUF_CT - e_ct[E_CT]) / l_ct;
	return (r == 0 ? SUCCESS : SYS_ERR);
}

#define USE 0
#define SAVE 1
static int					fill_tscdgfxyrz(
	size_t *dims,
	t_list *bs,
	t_s_cdgfxyrz *ret)
{
	size_t		ct_all;
	size_t		sz;
	t_s_cxyd	*ar;
	t_s_cxyd	*p_ar;

	ct_all = dims[DIM_R] * dims[DIM_C];
	if (!(ar = malloc(sizeof(t_s_cxyd) * ct_all)))
		return (SYS_ERR);
	p_ar = ar + ct_all;
	if ((sz = ct_all % BUF_CT))
		ft_memcpy((p_ar -= sz), bs->content, sz * sizeof(t_s_cxyd));
	sz = BUF_CT * sizeof(t_s_cxyd);
	while ((bs = bs->next))
		ft_memcpy((p_ar -= BUF_CT), bs->content, sz);
	ret->x_sz = dims[DIM_R];
	ret->y_sz = dims[DIM_C];
	ret->ar = ar;
	ft_memcpy(ret->at, &(double[3]){0, 0, 0}, sizeof(double[3]));
	return (SUCCESS);
}

int							get_cdgfxyrz_sbi(
	char const *file,
	t_s_sbi **ret)
{
	int				fd;
	size_t			dims[2];
	t_list			*bs;
	t_s_cdgfxyrz	*p;

	p = 0;
	*ret = 0;
	if (open_file(file, &fd) == SUCCESS &&
		parse_cdgfxyrz_sncnl(fd, dims, &bs) == SUCCESS &&
		(p = malloc(sizeof(t_s_cdgfxyrz))) &&
		fill_tscdgfxyrz(dims, bs, p) == SUCCESS &&
		(*ret = malloc(sizeof(t_s_sbi))))
		**ret = (t_s_sbi){e_sit_cdgfxyrz, p};
	else if (p)
			free(p);
	if (fd >= 0)
		close(fd);
	ft_lstdel(&bs, 0);
	return (*ret ? SUCCESS : SYS_ERR);
}
