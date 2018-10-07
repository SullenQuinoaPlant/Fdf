/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 03:31:08 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/07 04:53:48 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "parse.h"
# include "scene.h"

/*
**In add_tssbis_to_scene:
** (t_s_sbi) string array is freed by function call.
** Will fail if pointer to string is not properly initialized.
*/
int							add_tssbis_to_scene(
	t_s_sbi	*input_str,
	t_s_s	*scene);

int							clone_tar(
	t_s_ta	*ta,
	void	***p_ret);

void						free_tar(
	void	**ar,
	size_t	ar_sz,
	size_t	e_sz);

void						free_tssbi_str(
	t_s_sbi	*str);

void						free_tsse(
	t_s_se	*se);

int							get_cdgfxyrz_sbi(
	char const	*file,
	t_s_sbi		**ret);

int							get_nxt_se(
	t_e_seg	grp,
	t_s_s	*s,
	t_tag	*ret,
	void	**ret_addr);

int							init_tsse(
	t_e_seg	g,
	t_s_se	*se);

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
	t_s_v	**ret);

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

int							reg_freetags(
	t_tag	first,
	t_tag	diff_with_last,
	t_s_s	*s,
	t_s_se	*grp);

void						scene_teardown(
	t_s_s	**s);

size_t						teseg_type_sz(
	t_e_seg	g);

int							tssv_tar_allocs(
	t_e_vpg	grp,
	t_s_s	*s);

#endif
