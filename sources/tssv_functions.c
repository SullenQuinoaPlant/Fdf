/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tssv_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 21:11:37 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/18 17:56:31 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "functions.h"
#include "scene.h"
#include "colors.h"

static int					ring_tssv_add_tar(
	void *p_seg,
	t_ring p_tssv)
{
	t_s_sv *const	v = (t_s_sv*)p_tssv;
	t_s_s *const	s = v->s;
	t_e_seg const	g = *(t_e_seg*)p_seg;
	t_s_ta *const	ta = &v->e[g].ta;
	int		r;

	if ((r = inc_tar_alloc(s, ta->e_sz, &ta->ar_sz, &ta->ar)) == SUCCESS)
		r = RING_SUCCESS;
	else
		r = RING_SYS_ERR;
	return (r);
}

int							tssvs_add_tar(
	t_e_seg grp,
	t_s_s *s)
{
	int		r;

	r = ring_apply(&s->v, ring_tssv_add_tar, &grp);
	r = r == RING_SUCCESS ? SUCCESS : SYS_ERR;
	return (r);
}

int							tssv_add_pxl_ars(
	t_vuint h,
	t_vuint w,
	t_s_sv *v)
{
	double const	nan = NAN;
	t_argb			*p1;
	double			*p2;
	size_t			sz;

	if ((p1 = malloc((sz = h * w) * sizeof(t_argb))) &&
		(p2 = malloc(sz * sizeof(double))))
	{
		while (sz--)
		{
			p2[sz] = nan;
			p1[sz] = COL_BLACK;
		}
		v->h = h;
		v->w = w;
		v->pxl = p1;
		v->pxl_prec = p2;
		return (SUCCESS);
	}
	if (p1)
		free(p1);
	return (SYS_ERR);
}

void						tssv_set_out_fd(
	int fd,
	t_s_sv *v)
{
	int		old_fd;

	if ((old_fd = v->out_fd) >= 0)
		close(old_fd);
	v->out_fd = fd;
}
