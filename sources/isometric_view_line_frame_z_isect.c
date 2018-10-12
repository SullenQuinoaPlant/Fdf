/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_view_line_frame_z_isect.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 00:20:01 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/13 00:40:40 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int								has_isect(
	double pnd[3][DIMS + ARGBS])
{
	
}

void							isometric_line_z_isect(
	double pnd[3][DIMS + ARGBS])
{
	double	isect[DIMS + ARGBS];
	double	d;
	double	p;
	double	r;
	int		i;
	i = 0;
	if ((d = pnd[DT][X]))
	{
		p = pnd[P1][X];
		set_mult_dims_arbg(pnd[P1], pnd[DT], (r = -p / d), isect[i++]);
		r = ((double)(v->w - 1) - p) / d;
		set_and_multiply(pnd, pnd[DT], r, isect[i++]);
	}
	if ((d = pnd[DT][Y]))
	{
		p = pnd[P1][Y];
		set_and_multiply(pnd, pnd[DT], (r = -p / d)), isect[i++]);
		r = ((double)(v->h - 1) - p) / d;
		set_and_multiply(pnd, pnd[DT], r, isect[i++]);
	}
	i = filter_isects(v, pnd, i, isect);
}
