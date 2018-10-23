#include "functions.h"
#include "parse.h"
#include "colors.h"

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

#define DONE SUCCESS 
#define NOT_DONE 1
static int					really_parse(
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
		return (DONE);
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

int							cdgfxyrz_parse(
	int fd,
	size_t *dims,
	int zmm[MIN_MAX_SZ],
	t_list **bs)
{
	char 		*l[2];
	size_t		counter[2];
	t_s_cxyd	*p;
	int			r;

	dims[ROW] = -1;
	ft_memcpy(zmm, (int[MIN_MAX_SZ]){INT_MAX, INT_MIN}, sizeof(int[2]));
	*bs = 0;
	ft_bzero(counter, sizeof(counter));
	while ((r = get_next_line(fd, &l[0])) > 0)
	{
		l[1] = l[0];
		ft_memcpy(dims, (size_t[2]){++dims[ROW], 0}, sizeof(size_t[2]));
		while ((counter[CT_E]-- || (r = new_buff(bs, counter, &p)) == SUCCESS) &&
			(r = really_parse((char const **)&l[1], zmm, &p) == NOT_DONE))
			dims[COL]++;
		free(l[0]);
		if (r != SUCCESS)
			return (r);
	}
	dims[ROW]++;
	return (r == 0 ? SUCCESS : SYS_ERR);
}
