/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 03:18:01 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/07 04:51:30 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "outer.h"
# include "scene_typedefs.h"
# include "parse_typedefs.h"

/*
**The following structure describes a cartesian grid wich:
** - is full in x and y dimensions: each x and y combination
**		within parse dimensions is assigned a value.
** - is "regular" in z dimension, by which we mean that at any
**		(x, y) position, one and only one z-axis value is assigned.
** - the parse is described in a 2-dimensional (t_cgfxyrz) array
**		where the dimensions are assigned as follows : ar[x][y]
** - the "at" array specifies where to place grid origin in scene, not optional.
*/
struct						s_cartesian_xy_dot
{
	int		z;
	t_argb	col;
};

struct						s_cartesian_dot_grid_fullxy_regularz
{
	size_t			x_sz;
	size_t			y_sz;
	double			at[3];
	t_s_cxyd		*ar;
};

enum						e_scene_input_types
{
	e_sit_empty,
	e_sit_cdgfxyrz,
	e_sit_sz
};

/*
**Scene builders, (*t_scene_builder)s, add elements to the scene,
**They take the following struct as an argument
*/
struct						s_scene_builder_input
{
	t_e_sit	type;
	void	*input;
};

#endif
