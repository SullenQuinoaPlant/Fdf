/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_projection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 20:53:53 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/11 21:55:42 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void						get_intersections(
	t_s_sv *v,
	t_u_sls *const loa)
{
	double	p1[DIMS];
	double	p2[DIMS];
	double	dlt[DIMS];
}

void							loa_proj(
	t_s_sv *v,
	void *line_or_arrow,
	t_u_spsv const *const *pts,
	void *tsloap)
{
	t_u_slsa *const	loa = (t_u_slsa*)line_or_arrow;
	t_s_loap *const	ret = (t_s_loap*)tsloap;
	t_vpos			isect[4];

	get_intersections(v, loa, isect);
	filter_intersections(isect);
	ft_memcpy(ret->ends, isect, sizeof(t_vpos) * 2);
}
