#include "scene.h"
#include "discrete_ratio_tracking.h"

static int					is_x_slope(
	t_vpos ends[2],
	t_ruint *dt_longdim,
	t_ruint *dt_shortdim,
	t_ruint *init_shortdim)
{
	t_vuint	dt_x;
	t_vuint	dt_y;
	char	is_x_slope;

	if (ends[1][X] > ends[0][X])
		dt_x = ends[1][X] - ends[0][X];
	else
		dt_x = ends[0][X] - ends[1][X];
	if (ends[1][Y] > ends[0][Y])
		dt_x = ends[1][Y] - ends[0][Y];
	else
		dt_x = ends[0][Y] - ends[1][Y];
	if ((is_x_slope = dt_x >= dt_y ? 1 : 0))
	{
		*dt_longdim = ends[1][X] - ends[0][X];
		*dt_shortdim = ends[1][Y] - ends[0][Y];
		*init_shortdim = ends[0][Y];
	}
	else
	{
		*dt_longdim = ends[1][Y] - ends[0][Y];
		*dt_shortdim = ends[1][X] - ends[0][X];
		*init_shortdim = ends[0][X];
	}
	return (is_x_slope);
}

void						print_line(
	t_s_sv *v,
	t_tag t)
{
	t_s_lp *const	l = &(v->e[e_slna].ar[t >> TPS])[t & TPM];
	t_delta_n_init	dec[ARGBS + 1];
	t_ruint			*dec_line;
	char			is_x_slope;

	
}
