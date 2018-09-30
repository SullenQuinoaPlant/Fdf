#ifndef _H
# define _H

typedef struct			s_p
{
	double	xyz[3];
}						t_s_p;
typedef double	(t_p)[3];

#endif


int						chg(
	long **ar,
	int x_sz,
	int y_sz,
	t_p **ret)
{
	int		i;
	int		j;
	t_s_p	**p;

	if (!(p = malloc(x_sz * y_sz * sizeof(t_p))))
		return (1);
	i = -1;
	while (++i < x_sz)
	{
		j = -1;
		while (++j < y_sz)
			p[i][j] = (t_p){i, j, ar[i][j]};
	}
	return (0);
}

# define SQ2 0x1.6a09e667f3bcdp+0
# define SQ3 0x1.bb67ae8584caap+0
# define SQ6 0x1.3988e1409212ep+1

static void				multiply(
	t_s_p *pt)
{
	t_s_p			ret;
	double const	m[3][3] = {
		{SQ3 / SQ6, 0, -SQ3 / SQ6},
		{1 / SQ6, 2 / SQ6, 1 / SQ6},
		{SQ2 / SQ6, -SQ2 / SQ6, SQ2 / SQ6},
	};
	int		i;
	int		j;
	double	xyz;

	i = -1;
	while (++i < 3)
	{
		xyz[i] = 0;
		j = -1;
		while (++j < 3)
			xyz[i] += m[i][j] * pt->xyz[j];
	}
	i = -1;
	while (++i < 3)
		pt[i] = xyz[i];
}

int						tr(
	int i,
	int j,
	t_p **ar)
{
	int		ii;
	int		jj;
	t_p		pt;

	ii = -1;
	while (++ii < i)
	{
		jj = -1;
		while (++jj < j)
			multiply(&ar[i][j]);
	}
}
