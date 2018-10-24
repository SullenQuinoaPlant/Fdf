/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tssv_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 21:11:37 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/24 22:35:21 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include "mlx.h"
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
	int				r;

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

	r = ring_apply(s->v, ring_tssv_add_tar, &grp);
	r = r == RING_SUCCESS ? SUCCESS : SYS_ERR;
	return (r);
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

void						tssv_push_to_displays(
	t_s_sv *v)
{
	t_s_s *const	s = v->s;

	if (v->mlx_wdw)
		mlx_put_image_to_window(s->mlx, v->mlx_wdw, v->pxl, 0, 0);
	if (v->out_fd > -1)
		tssv_print_ascii(v);
}

void						tssv_reset_print_canvas(
	t_s_sv *v)
{
	t_argb *const	lim1 = v->pxl + v->h * v->w;
	double *const	lim2 = v->pxl_prec + v->h * v->w;
	t_argb			*p1;
	double			*p2;

	if ((p1 = v->pxl))
		while (p1 < lim1)
			*p1++ = COL_BLACK;
	if ((p2 = v->pxl_prec))
		while (p2 < lim2)
			*p2++ = DBL_MAX;
}
