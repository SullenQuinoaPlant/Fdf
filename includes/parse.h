/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 03:18:01 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/23 20:58:44 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "outer.h"
# include "scene_typedefs.h"
# include "parse_typedefs.h"

enum						e_scene_input_types
{
	e_sit_empty,
	e_sit_cdgfxyrz,
	e_sit_sz
};

/*
**The following structure describes a cartesian grid wich:
** - is full in x and y dimensions: each x and y combination
**		within parse dimensions is assigned a value.
** - is "regular" in z dimension, by which we mean that at any
**		(x, y) position, one and only one z-axis value is assigned.
** - the parse is described in a 2-dimensional (t_cgfxyrz) array
**		where the dimensions are assigned as follows : ar[x][y]
** - 'at' : specifies where to place grid origin in scene, not optional.
**		This array must be present in first position in all input
**		describing structures.
**
**Grid rows are along the y axis, grid columns are along the x axis.
*/
struct						s_cartesian_xy_dot
{
	int		z;
	t_argb	col;
};

struct						s_cartesian_dot_grid_fullxy_regularz
{
	t_xyz			at;
	size_t			x_sz;
	size_t			y_sz;
	int				zmm[MIN_MAX_SZ];
	t_s_cxyd		*ar;
};

/*
**Scene builders, (*t_scene_builder)s, add elements to the scene.
**They take the following struct as an argument.
** - 'minmax' : gives the coordinates of furthest points along the axes
** - 'type' : specifies what the 'input' (void*) must be cast to.
** - 'input' : pointer to an input-specific structure.
*/
struct						s_scene_builder_input
{
	t_xyz	minmax[MIN_MAX_SZ];
	t_e_sit	type;
	void	*input;
};

/*
**Builder auxilliary functions:
*/
/*
**cdgfxyrz :
*/
void						cdgfxyrz_set_sbi_minmax(
	t_s_cdgfxyrz *parsed,
	t_s_sbi *sbi);

int							cdgfxyrz_add_lines(
	t_s_cdgfxyrz	*p,
	t_tag			*tags,
	t_s_s			*scene,
	t_s_o			*object);

int							cdgfxyrz_parse(
	int			fd,
	size_t		*dims,
	int			zmm[MIN_MAX_SZ],
	t_list		**bs);

#endif
