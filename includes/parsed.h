#ifndef PARSED_H
# define PARSED_H

/*
**The following structure describes a cartesian grid wich:
** - is full in x and y dimensions: each x and y combination
**	 within parse dimensions is assigned a value.
** - is "regular" in z dimension, by which we mean that at any
**	(x, y) position, one and only one z-axis value is assigned.
** - the parse is described in a 3-dimensional (t_cgfxyrz) array
**	where the dimensions are assigned as follows : ar[x][y][z]
*/
typedef int	(**t_cgfxyrz)[1];
typedef struct				s_cartesian_grid_fullxy_regularz
{
	unsigned int	x-sz;
	unsigned int	y-sz;
	t_cgfxyrz		ar;
}							t_s_rfcgx;

#endif
