/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 03:31:08 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/20 19:14:15 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "parse_typedefs.h"
# include "scene_typedefs.h"
# include "discrete_ratio_tracking.h"
# include "line_frame_intersections.h"

t_s_pctr					*add_camera(
	t_pctrm	const	*coordinate_transforms__cts,
	int				coordinate_transforms_count__ct_ct,
	t_s_pctr		**add_at);
//	t_s_s			*s);

int							add_isometric_v(
	t_vpos	view_height_and_width__hw,
	t_zntr	view_camera_position__cam_pos,
	t_s_s	*s);

t_s_pctr					*add_isometric_camera(
	t_zntr	zoom_and_translation__zntr,
	t_s_s	*s);

int							add_star(
	t_e_seg group,
	t_s_s	*scene);

int							add_tssbis_to_scene(
	t_s_sbi	**input_str,
	t_s_s	*scene);

int							add_view(
	t_s_s	*s,
	t_s_sv	**ret);

int							alloc_tar(
	t_s_s	*s,
	size_t	type_sz,
	size_t	*ar_sz,
	void	***p_ar);

int							chg_grptag_refct(
	t_e_seg	g,
	t_tag	t,
	int		chg,
	t_s_s	*s);

int							chg_setag_refct(
	t_s_se	*se,
	t_tag	t,
	int		chg,
	t_s_s	*s);

int							cdgfxyrz_builder(
	void	*sbi,
	t_s_s	*s);

int							clone_tar(
	t_s_ta	*ta,
	void	***p_ret);

void						doubles_to_targb(
	double	argb[ARGBS],
	t_argb	*ret);

void						doubles_to_tvpos(
	double	coords[DIMS],
	t_vpos	*ret);

void						free_free_tar(
	void	**ar,
	size_t	ar_sz,
	size_t	e_sz);

void						free_object_lists(
	t_s_o	*object);

void						free_tar(
	void	**ar,
	size_t	ar_sz,
	size_t	e_sz,
	t_s_s	*s);

void						free_tscdgfxyrz(
	void	*p);

void						free_tso_tsse_content(
	t_s_se	*tso_tsse);

void						free_tssbi_str(
	t_s_sbi	**str);

void						free_tsse(
	t_s_se	*se,
	t_s_s	*s);

void						free_view(
	t_s_sv	**ring);

void						free_views(
	t_s_sv	**ring);

int							get_cdgfxyrz_sbi(
	char const	*file,
	t_s_sbi		**ret);

int							get_nxt_se(
	t_e_seg	grp,
	t_s_s	*s,
	t_tag	*ret,
	void	**ret_addr);

void						*get_se(
	t_s_s const	*s,
	t_e_seg		g,
	t_tag		t);

size_t						get_ve_size(
	t_e_seg	g);

int							inc_tar_alloc(
	t_s_s	*s,
	size_t	type_sz,
	size_t	*ar_sz,
	void	***p_ar);

int							init_tsse(
	t_e_seg	g,
	t_s_se	*se,
	t_s_s	*s);

int							initiate_se_release(
	void	*se);

int							is_iso_visible(
	t_s_sv	*v,
	t_xyz	pt);

int							is_iso_xy_visible(
	t_s_sv	*v,
	t_xyz	pt);

int							is_iso_z_visible(
	t_xyz	pt);

int							iso_dbl_dims_to_tvpos(
	t_s_sv const	*v,
	double const	pos[DIMS],
	t_vpos			ret);

int							iso_dbl_to_tvuint(
	t_vuint const	dim_sz,
	double const	d,
	t_vuint			*ret);

int							iso_dbl_within_dimsz(
	t_vuint const	dim_sz,
	double			d);

void						isometric_dot_proj(
	t_s_sv				*v,
	void				*dot,
	t_s_pp const *const	*points,
	void				*ret_proj);

void						isometric_line_proj(
	t_s_sv				*v,
	void				*line,
	t_s_pp const *const	*points,
	void				*ret_proj);

int							isometric_line_xy_isect(
	t_s_sv	*v,
	t_pdp	pnd);

int							isometric_line_z_isect(
	t_pdp	pnd);

/*
**Allocates and initilizes a scene, with optional
**initial elements passed through input_str.
**If input_str is not null, make_scene always frees the contents.
*/
int							make_scene(
	t_s_sbi	**input_str,
	t_s_s	**p_ret_scene);

t_e_seg						map_seg_to_vpg(
	t_e_seg	sg);

int							mirror_tsta(
	t_s_s			*s,
	t_s_ta const	*model,
	size_t			e_sz,
	t_s_ta			*reflection);

void						mult_dbl_ar(
	double mult,
	size_t sz,
	double *ar);

int							new_view(
	t_s_s	*s,
	t_s_sv	**ret);

int							nxt_active_obj(
	t_s_s	*s,
	t_s_o	**ret,
	t_tag	*ret_tag);

void						obj_projection(
	t_s_sv				*v,
	void				*obj,
	t_s_pp const *const	*points,
	void				*ret);

int							open_file(
	char const	*file,
	int			*ret_fd);

void						point_projection(
	t_s_sv	*v,
	void	*scene_point,
	t_s_pp const *const *invalid,
	void	*view_point);

int							print_arrow(
	t_s_sv	*v,
	t_tag	t);

int							print_dot(
	t_s_sv	*v,
	t_tag	t);

int							print_fill(
	t_s_sv	*v,
	t_tag	t);

int							print_line(
	t_s_sv	*v,
	t_tag	t);

int							print_object(
	t_s_sv	*v,
	t_tag	t);

void						print_scene_points(
	t_s_s	*s);

int							realloc_tars(
	t_s_s	*s);

int							reg_teseg_freetags(
	t_tag	first,
	t_tag	diff_with_last,
	t_s_s	*s,
	t_e_seg	group);

int							reg_tsse_freetags(
	t_tag	first,
	t_tag	diff_with_last,
	t_s_s	*s,
	t_s_se	*tsse);

void						report_error(
	int		err);

void						scene_teardown(
	t_s_s	**s);

void						set_mult_pnt_dec(
	double	src[DIMS],
	double	deltas[DIMS],
	double	ratio,
	double	dest[DIMS]);

void						set_tpctrm_identity(
	t_pctrm	ret);

int							sign(
	double	d);

int							tar_alloc(
	t_s_s	*s,
	size_t	type_sz,
	void	**p_alloc);

void						targb_to_doubles(
	t_argb	argb,
	double	ret[ARGBS]);

size_t						teseg_type_sz(
	t_e_seg	group);

void						tpctrm_apply(
	t_pctrm	apply_this,
	t_xyz	to_this,
	t_xyz	store_here);

void						tpctrm_mult(
	t_pctrm const	this_a,
	t_pctrm const	times_this_b,
	t_pctrm 		equals_this_c);

int							track_pixel_line(
	t_s_lp const *const	lp,
	t_ruint				*ret_dt,
	int					*ret_along,
	t_ruint				**ret);

void						track_ratios(
	t_ruint const	over_delta__dt,
	t_dni			*these__vals,
	int const		of_which_there_are__v_ct,
	t_ruint			*ret);

void						truint_dec_to_targb(
	t_ruint	*decomposed_targb__dec,
	t_argb	*ret);

void						tspctr_onelessview(
	t_s_pctr	*p_coord_transform);

int							tssv_add_pxl_ars(
	t_vuint	h,
	t_vuint	w,
	t_s_sv	*v);

void						tssv_apply_projs(
	t_s_sv	*v);

void						tssv_grp_apply_proj(
	t_s_sv	*v,
	t_s_se	*s_grp,
	t_s_ve	*v_grp);

int							tssv_print_ascii(
	t_s_sv	*v);

int							tssv_tar_allocs(
	t_e_seg	grp,
	t_s_s	*s);

int							tssvs_add_tar(
	t_e_seg	grp,
	t_s_s	*s);

void						txyz_to_ttpr(
	t_xyz const	in,
	t_tpr		out);

int							usage(
	void);

#endif
