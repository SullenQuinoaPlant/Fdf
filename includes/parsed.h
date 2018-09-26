#ifndef PARSED_H
# define PARSED_H

# include <stddef.h>
# include <stdint.h>

/*
**The following structure describes a cartesian grid wich:
** - is full in x and y dimensions: each x and y combination
**	 within parse dimensions is assigned a value.
** - is "regular" in z dimension, by which we mean that at any
**	(x, y) position, one and only one z-axis value is assigned.
** - the parse is described in a 3-dimensional (t_cgfxyrz) array
**	where the dimensions are assigned as follows : ar[x][y][z]
** - the has_pos switch in combination twith the position[] can
**	be used to specify a location for the grid in scene space. If
**	none is given, scene builder will attempt to do something reasonable.
*/
typedef int	(**t_cpgfxyrz)[1];
typedef struct				s_cartesian_point_grid_fullxy_regularz
{
	size_t			x_sz;
	size_t			y_sz;
	t_cpgfxyrz		ar;
	int				has_pos;
	int				position[3];
}							t_s_cpgfxyrz;

typedef enum				e_scene_input_types
{
	e_sit_empty,
	e_sit_cpgfxyrz,
	e_sit_sz
}							t_e_sit;

typedef struct				s_scene_builder_input
{
	t_e_sit	type,
	void	*input;
}							t_s_sbi;
#endif
