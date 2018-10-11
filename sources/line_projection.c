/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_projection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 20:53:53 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/11 23:10:01 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void						set_and_multiply(
	double *src,
	double mult,
	double *dest)
{
	int		i;

	ft_memcpy(dest, src, sizeof(double) * DIMS);
	int = -1;
	while (++i < DIMS)
		dest[i] *= mult;
}
/*
**Get intersection points between the lines that prolong the viewing frame
** and the line we want to draw.
**
** x = 0
** y = 0
** y = w - 1
** x = h - 1
**
** abbreviations:
** - dlt : deltas
*/
static int						get_intersections(
	t_s_sv *v,
	t_u_slsa *const loa,
	t_u_spsv const *const *pts,
	double *ret)
{
	double	dlt[DIMS];
	t_tag	t;
	double	*p;
	int		i;

	ft_memcpy(dlt, (pts[(t = loa->ends[2]) >> TPS])[t & TPM].xyz, sizeof(dlt));
	p = (pts[(t = loa->ends[1]) >> TPS])[t & TPM].xyz;
	i = -1;
	while (++i < DIMS)
		dlt[i] -= d[i];
	i = 0;
	if (dlt[X])
	{
		set_and_multiply(p, -(p[X] / dlt[X]), &ret[i++]);
		set_and_multiply(p, ((double)(v->h - 1) - p[X]) / dlt[X]), &ret[i++]);
	}
	if (dlt[Y])
	{
		set_and_multiply(p, -(p[Y] / dlt[Y]), &ret[i++]);
		set_and_multiply(p, ((double)(v->w - 1) - p[Y]) / dlt[Y]), &ret[i++]);
	}
	return (i);
}

static void						filter_intersections(
	t_s_sv *v,
	double (*isecs)[DIMS],
	int isec_count,
	t_vpos *ret)
{
	double const	h = (double)v->h;
	double const	w = (double)v->w;
	double	(*p)[DIMS];
	int		i;

	i = 0;
	while (isec_count--)
	{
		p = isecs[isec_count];
		if (p[X] <= h
	}

/*
** A line may cross the rectangular views' boundaries four times when we extend
** these to infinity. Therefore isect[4].
*/
void							loa_proj(
	t_s_sv *v,
	void *line_or_arrow,
	t_u_spsv const *const *pts,
	void *tsloap)
{
	t_u_slsa *const	loa = (t_u_slsa*)line_or_arrow;
	t_s_loap *const	ret = (t_s_loap*)tsloap;
	double			isect[4][DIMS];
	int				count;

	count = get_intersections(v, loa, pts, isect);
	filter_intersections(v, isect, count, ret->ends);
}
