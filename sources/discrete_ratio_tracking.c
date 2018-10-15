/*
**Don't use if (delta-x plus delta-y minus one) is more than INTMAX
**Be careful or be sorry.
**
**Abbreviations:
**
*/

static void					init_ars(
	t_ruint ar_len,
	int ar_ct,
	t_delta_n_first *p_init,
	t_ruint *p_ars)
{
	t_ruint	init;
	int		i;
	int		j;

	i = -1;
	while (++i < ar_ct)
	{
		init = p_init[i][INIT];
		j = -1;
		while (++j < ar_len)
			p_ars[i][j] = init;
	}
	i = -1;
	while (++i < ar_ct)
		p_init[FIRST] = ar_len / 2;
}

int							track_ratios(
	t_ruint			dt,
	t_delta_n_first	*vals,
	int const		v_ct,
	t_ruint			**ret)
{
	size_t const	len = dt + 1;
	int				i;
	int				j;
	t_ruint			(*p_ret)[len];
	t_ruint			*track;

	if ((*ret = malloc(sizeof(t_ruint) * len * v_ct)) &&
		(track = malloc(sizeof(t_ruint) * v_ct)))
	{
		init_ars(vals, len, v_ct, (p_ret = *ret)) 
		i = -1;
		while (++i < v_ct)
		{
			j = -1;
			while (++j < dt)
			{
				p_ret[i][j] += vals[i][DT];
				if (p_ret[i][j] >= dt)
				{
					p_ret[i][j + 1] = 
		}
	}
	if (*ret && track)
		free(track);
	return (SYS_ERR);
}
