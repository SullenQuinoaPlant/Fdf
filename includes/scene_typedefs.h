/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_typedefs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 02:35:29 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/18 17:42:30 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_TYPEDEFS_H
# define SCENE_TYPEDEFS_H

# include "outer.h"

typedef uint32_t	t_argb;

typedef enum e_scene_element_groups	t_e_seg;

typedef enum e_view_projection_groups	t_e_vpg;

typedef union u_spsv	t_u_spsv;

typedef void	(*t_pctr)(\
	void *arg,
	t_u_spsv const *const *tuspsv_ar,
	size_t tuspsv_ar_sz,
	t_u_spsv *const *ret);

typedef double	(t_pctrmr)[DIMS];

typedef struct s_scene_view	t_s_sv;

typedef unsigned int	t_tag;

typedef void	(*t_printer)(
	t_s_sv *view,
	t_tag tag);

typedef double	(t_xyz)[DIMS];

typedef double	(t_tpr)[DIMS];

typedef t_xyz	(t_pctrm)[DIMS + 1];

typedef struct s_point_projection	t_s_pp;

typedef void	(*t_proj)(
	t_s_sv *scene_view,
	void *project_this,
	t_s_pp const *const *using_these,
	void *store_here);

typedef int	t_refct;

typedef struct s_arrow	t_s_a;

typedef struct s_arrow_projection	t_s_ap;

typedef struct s_active_object	t_s_ao;

typedef struct s_dot	t_s_d;

typedef struct s_dot_projection	t_s_dp;

typedef struct s_fill	t_s_f;

typedef struct s_fill_projection	t_s_fp;

typedef struct s_free_tags	t_s_ft;

typedef struct s_line	t_s_l;

typedef struct s_line_projection	t_s_lp;

typedef struct s_object	t_s_o;

typedef struct s_object_projection	t_s_op;

typedef struct s_object_handle	t_s_oh;

typedef struct s_point	t_s_p;

typedef struct s_point_coordinates_transform	t_s_pctr;

typedef struct s_pixel	t_s_pxl;

typedef struct s_scene	t_s_s;

typedef struct s_scene_elements	t_s_se;

typedef struct s_tagged_array	t_s_ta;

typedef t_s_p	t_s_v;

typedef double	t_zntr[DIMS + 1];

typedef unsigned int	t_vuint;

typedef t_vuint	(t_vpos)[VIEW_DIMS];

#endif
