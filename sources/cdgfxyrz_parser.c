#include "functions.h"
#include "parse.h"
#include "colors.h"

#define BUF_SZ 256
#define CT_E 0
#define CT_ALLOCS 1

static int					new_buff(
	t_list **prv,
	size_t *counter,
	t_s_cxyd **p)
{
	t_list		*new;
	t_s_cxyd	*ar;

	new = 0;
	if ((ar = malloc(BUF_SZ * sizeof(t_s_cxyd))) &&
		(new = ft_lstnew(0, 0)))
	{
		*p = ar;
		new->content = ar;
		new->content_size = BUF_SZ * sizeof(t_s_cxyd);
		ft_lstadd(prv, new);
		counter[CT_E] = BUF_SZ;
		counter[CT_ALLOCS]++;
	}
	else if (ar)
		free(ar);
	return (new ? SUCCESS : SYS_ERR);
}

#define NOT_DONE 1
static int					parse_like_really(
	char const **str,
	int zmm[MIN_MAX_SZ],
	t_s_cxyd **p)
{
	char 		*s;
	t_argb		col;
	int			z;

	s = (char*)*str;
	col = COL_WHITE;
	if (!*s)
		return (SUCCESS);
	if (ft_atoierr(s, &z, &s) ||
		(*s == ',' && ft_axtoierr(++s, (int*)&col, &s)) ||
		(*s && *s++ != ' '))
		return (BAD_INFILE);
	*str = (char const*)s;
	*((*p)++) = (t_s_cxyd){z, col};
	if (z < zmm[MIN])
		zmm[MIN] = z;
	else if (z > zmm[MAX])
		zmm[MAX] = z;
	return (NOT_DONE);
}

/*
**Constants to access rows and columns:
*/
#define DIM_R 0
#define DIM_C 1

int							parse_cdgfxyrz(
	int fd,
	size_t *dims,
	int zmm[MIN_MAX_SZ],
	t_list **bs)
{
	char 		*l[2];
	size_t		l_ct;
	size_t		counter[2];
	t_s_cxyd	*p;
	int			r;

	*bs = 0;
	l_ct = 0;
	ft_bzero(counter, sizeof(counter));
	ft_memcpy(zmm, (int[MIN_MAX_SZ]){INT_MAX, INT_MIN}, sizeof(int[2]));
	r = 0;
	while ((r = get_next_line(fd, &l[0])) > 0)
	{
		l[1] = l[0];
		l_ct++;
		while ((counter[CT_E] || (r = new_buff(bs, counter, &p)) == SUCCESS) &&
			(r = parse_like_really((char const **)&l[1], zmm, &p) == NOT_DONE))
			counter[CT_E]--;
		free(l[0]);
		if (r != SUCCESS)
			return (r);
	}
	dims[DIM_R] = l_ct;
	dims[DIM_C] = (counter[CT_ALLOCS] * BUF_SZ - counter[CT_E]) / l_ct;
	return (r == 0 ? SUCCESS : SYS_ERR);
}

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
	if ((sz = ct_all % BUF_SZ))
		ft_memcpy((p_ar -= sz), bs->content, sz * sizeof(t_s_cxyd));
	sz = BUF_SZ * sizeof(t_s_cxyd);
	while ((bs = bs->next))
		ft_memcpy((p_ar -= BUF_SZ), bs->content, sz);
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
	int				r;

	bs = 0;
	if ((p = malloc(sizeof(t_s_cdgfxyrz))) &&
		(r = open_file(file, &fd)) == SUCCESS &&
		(r = parse_cdgfxyrz(fd, dims, p, &bs)) == SUCCESS &&
		fill_tscdgfxyrz(dims, bs, p) == SUCCESS &&
		(*ret = malloc(sizeof(t_s_sbi))))
	{
		(**ret).type = e_sit_cdgfxyrz;
		(**ret).input = p;
		cdgfxyrz_set_sbi_minmax(p, *ret);
	}
	else if (p)
		free(p);
	if (fd >= 0)
		close(fd);
	ft_lstdel(&bs, ft_cleanfree);
	return (r == SUCCESS && !*ret ? SYS_ERR : r);
}
