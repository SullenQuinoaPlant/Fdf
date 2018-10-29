#include "functions.h"
#include "parse.h"

static int					fill_tscdgfxyrz(
	size_t *dims,
	t_list *bs,
	t_s_cdgfxyrz *ret)
{
	size_t		ct_all;
	size_t		sz;
	t_s_cxyd	*ar;
	t_s_cxyd	*p_ar;

	ct_all = dims[ROW] * dims[COL];
	if (!(ar = malloc(sizeof(t_s_cxyd) * ct_all)))
		return (SYS_ERR);
	p_ar = ar + ct_all;
	if ((sz = ct_all % BUF_SZ))
		ft_memcpy((p_ar -= sz), bs->content, sz * sizeof(t_s_cxyd));
	sz = BUF_SZ * sizeof(t_s_cxyd);
	while ((bs = bs->next))
		ft_memcpy((p_ar -= BUF_SZ), bs->content, sz);
	ret->x_sz = dims[ROW];
	ret->y_sz = dims[COL];
	ret->ar = ar;
	ft_memcpy(ret->at, &(double[3]){0, 0, 0}, sizeof(double[3]));
	return (SUCCESS);
}

static void					init_cdgfxyrz_sbi(
	t_s_cdgfxyrz *p,
	t_s_sbi *ret)
{
	ret->type = e_sit_cdgfxyrz;
	ret->input = p;
	cdgfxyrz_set_sbi_minmax(p, ret);
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
	fd = -1;
	*ret = 0;
	ft_bzero(dims, sizeof(dims));
	r = SYS_ERR;
	if ((p = malloc(sizeof(t_s_cdgfxyrz))) &&
		(r = open_file(file, &fd)) == SUCCESS &&
		(r = cdgfxyrz_parse(fd, dims, p->zmm, &bs)) == SUCCESS &&
		(r = fill_tscdgfxyrz(dims, bs, p)) == SUCCESS &&
		(*ret = malloc(sizeof(t_s_sbi))))
		init_cdgfxyrz_sbi(p, *ret);
	else if (p)
		free(p);
	if (fd >= 0)
		close(fd);
	ft_lstdel(&bs, ft_cleanfree);
	return (r == SUCCESS && !*ret ? SYS_ERR : r);
}
