#ifndef OBJECTS_H
# define OBJECTS_H

# include "outer.h"

/*
**Things that live in the scene, or that impact
**the scene display; stuff.
*/

/*
**s_point describes a point in space.
*/
typedef struct				s_point
{
	union
	{
		struct cart
		{
			int		x;
			int		y;
			int		z;
		};
		struct
		{
			int		x;
			int		y;
			int		z;
		};
	};
	union
	{
		struct polr
		{
			double	t;
			double	p;
			double	r;
		};
		struct
		{
			double	t;
			double	p;
			double	r;
		};
	};
	int		refs;
}							t_s_p;

/*
**t_s_v stands for typedef struct vector
**represents vectors as (point) - (0,0,0):
*/
typedef t_s_p	t_s_v;


**Visible objects:
*/
typedef struct				s_dot
{
	t_s_p	pos;
	t_rgba	rgba;
	int		refs;
}

# define L_END1 0
# define L_END2 1
# define L_END 0
# define L_VEC 1
typedef struct				s_line
{
	union
	{
		t_s_p	ends[2];
		t_s_p	pnr[2];
	}
	t_rgba	rgba[2];
	int		refs;
}							t_s_l;

#endif
