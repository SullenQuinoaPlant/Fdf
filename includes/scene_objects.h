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
	t_tag	pos;
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
	t_tag	pos;
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
	t_tag	pos;
}							t_s_l;

# define VERT1 0
# define VERT2 1
# define VERT3 2
typedef struct				s_area
{
	t_s_p	vertices[3];
	t_rgba	rgba[3];
	t_s_v	out_norm;
	int		refs;
	t_tag	pos;
}							t_s_a;

/*
**Scene active objects, can be acted upon:
*/
typedef struct s_object	t_s_o;
struct						s_object
{
	t_s_d	*dot_str;
	t_s_l	*line_str;
	t_s_a	*area_str;
	t_s_o	*subobjs_str;
};

#endif
