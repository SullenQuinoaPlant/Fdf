#include "discrete_ratio_tracking.h"

/*
**Don't use if (2 * (delta-x minus one)) is more than max value for t_ruint
**Be careful or be sorry.
*/

static void					track_ratio(
	t_ruint const dt,
	t_ruint dt_v,
	t_ruint start_v,
	t_ruint *ar)
{
	int const		len = dt + 1;
	int const		sign = dt_v > dt ? -1 : 1;
	t_ruint			err_sum;
	t_ruint			track;
	unsigned int	i;

	track = start_v;
	ar[0] = track;
	dt_v *= sign;
	i = 0;
	err_sum = dt / 2;
	while (++i < dt)
	{
		if ((err_sum += dt_v) >= dt)
		{
			err_sum -= dt_v;
			track += sign;
		}
		ar[i * len] = track;
	}
}

int							track_ratios(
	t_ruint const dt,
	t_dni *vals,
	int const v_ct,
	t_ruint **ret)
{
	size_t const	len = dt + 1;
	int				i;
	t_ruint			(*p_ret)[len];

	*ret = 0;
	if ((p_ret = malloc(sizeof(t_ruint) * len * v_ct)))
	{
		i = -1;
		while (++i < v_ct)
			track_ratio(dt, vals[i][DT], vals[i][INIT], p_ret[i]);
		*ret = &p_ret[0][0];
		return (SUCCESS);
	}
	return (SYS_ERR);
}
