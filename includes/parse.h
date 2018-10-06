#ifndef PARSE_H
# define PARSE_H

# include "scene.h"

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
typedef struct				s_cartesian_xy_dot
{
	int		z;
	t_argb	col;
}							t_s_cxyd;

typedef t_s_cxyd	(*t_cdgfxyrz)[][1];

typedef struct				s_cartesian_dot_grid_fullxy_regularz
{
	size_t			x_sz;
	size_t			y_sz;
	t_cdgfxyrz		ar;
	double			at[3];
}							t_s_cdgfxyrz;

typedef enum				e_scene_input_types
{
	e_sit_empty,
	e_sit_cdgfxyrz,
	e_sit_sz
}							t_e_sit;

typedef struct				s_scene_builder_input
{
	t_e_sit	type;
	void	*input;
}							t_s_sbi;
#endif
