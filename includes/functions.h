/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 03:31:08 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/14 05:06:14 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "parse_typedefs.h"
# include "scene_typedefs.h"
# include "libgetnextline.h"

int							add_star(
	t_e_seg group,
	t_s_s	*scene);

/*
**In add_tssbis_to_scene:
**	string is freed no matter what.
*/
int							add_tssbis_to_scene(
	t_s_sbi	*input_str,
	t_s_s	*scene);

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
	t_s_sbi	*sbi,
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

void						free_tar(
	void	**ar,
	size_t	ar_sz,
	size_t	e_sz);

void						free_tscdgfxyrz(
	t_s_sbi	*p);

void						free_tssbi_str(
	t_s_sbi	*str);

void						free_tsse(
	t_s_se	*se);

void						free_view(
	t_s_sv	*ring);

void						free_views(
	t_s_sv	*ring);

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

int							init_tsse(
	t_e_seg	g,
	t_s_se	*se,
	t_s_s	*s);

int							initiate_se_release(
	void	*se);

int							is_iso_visible(
	t_s_sv *v,
	double pt[DIMS]);

int							is_iso_xy_visible(
	t_s_sv *v,
	double pt[DIMS]);

int							is_iso_z_visible(
	t_s_sv *v,
	double pt[DIMS]);

/*
**Allocates and initilizes a scene, with optional
**initial elements passed through input_str.
**If input_str is not null, make_scene always frees the contents.
*/
int							make_scene(
	t_s_sbi	*input_str,
	t_s_s	**p_ret_scene);

t_e_vpg						map_seg_to_vpg(
	t_e_seg	sg);

int							new_view(
	t_s_s	*s,
	t_s_sv	**ret);

int							nxt_active_obj(
	t_s_s	*s,
	t_s_o	**ret,
	t_tag	*ret_tag);

void						onelessview(
	t_s_pctr	*p_coord_transform);

int							open_file(
	char const	*file,
	int			*ret_fd);

void						prinrt_scene_points(
	t_s_s	*s);

int							realloc_tars(
	t_s_s	*s);

int							reg_tesegfreetags(
	t_tag	first,
	t_tag	diff_with_last,
	t_s_s	*s,
	t_e_seg	group);

int							reg_tssefreetags(
	t_tag	first,
	t_tag	diff_with_last,
	t_s_s	*s,
	t_s_se	*tsse);

void						scene_teardown(
	t_s_s	**s);

void						set_mult_dims_argb(
	double	src[DIMS],
	double	deltas[DIMS],
	double	ratio,
	double	dest[DIMS]);

void						set_tpctrm_identity(
	t_pctrm	ret);

int							sign(
	double	d);

void						targb_to_doubles(
	t_argb	argb,
	double	ret[ARGBS]);

size_t						teseg_type_sz(
	t_e_seg	g);

void						tpctrm_mult(
	t_pctrm const	a,
	t_pctrm const	b,
	t_pctrm 		c);

int							tssv_tar_allocs(
	t_e_vpg	grp,
	t_s_s	*s);

#endif
