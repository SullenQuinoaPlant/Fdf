#ifndef OBJECTS_H
# define OBJECTS_H

# include "outer.h"

/*
**Things that live in the scene, or that impact
**the scene display; stuff.
**
**NOTE :
**	- the reference count changing functions
**		rely on "refs" being the first 
**		structure member.
*/

/*
**s_point describes a point in space.
*/

# define X 0
# define Y 1
# define Z 2

typedef struct				s_point
{
	union
	{
		struct cart
		{
			double		x;
			double		y;
			double		z;
		};
		struct
		{
			double		x;
			double		y;
			double		z;
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
	unsigned int	refs;
}							t_s_p;

typedef struct				s_vector
{
	union
	{
		struct cart
		{
			double		x;
			double		y;
			double		z;
		};
		struct
		{
			double		x;
			double		y;
			double		z;
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
	unsigned int	refs;
}							t_s_v;

typedef union				u_spsv
{
	t_s_p	p;
	t_s_v	v;
}							t_u_spsv;

/*
**Visible objects:
*/
typedef struct				s_dot
{
	t_tag	pos_p;
	t_argb	argb;
	unsigned int	refs;
}							t_s_d;

/*
**lines are represented by two extremities; they
**	are finite segments (but letter 's' already used).
*/
# define L_END1 0
# define L_END2 1
typedef struct				s_line
{
	t_tag	end_p[2];
	t_argb	argb[2];
	unsigned int	refs;
}							t_s_l;
/*
**arrows are vectors positioned in space.
*/
# define A_POS 0
# define A_VEC 1
typedef struct				s_arrow
{
	t_tag	pnv[2];
	t_argb	argb[2];
	unsigned int	refs;
}							t_s_a;

typedef union				u_slsa
{
	t_s_l	l;
	t_s_a	a;
}							t_u_slsa;


/*
**In s_fill:
** - norm_v (normal vector) points outwards from the filled surface.
*/
# define VERTEX1 0
# define V1 VERTEX1
# define VERTEX2 1
# define V2 VERTEX2
# define VERTEX3 2
# define V3 VERTEX3
typedef struct				s_fill
{
	t_tag	vrt_p[3];
	t_argb	argb[3];
	t_tag	norm_v;
	unsigned int	refs;
}							t_s_f;

/*
**Scene objects, can be displayed
*/
/*
**Array of tags that are part of an object.
**count are used, from index 0.
**sz is array size. May have trailing unused tag slots.
*/
typedef struct				s_tag_array
{
	t_tag	*ar;
	size_t	count;
	size_t	sz;
}							t_s_ta;

/*
**In t_s_o:
** - pnvs: points 'n vectors (u_spsv)s
** - dots: (t_s_d)s
** - lnas: lines 'n arrows (u_slsa)s
** - fills: (t_s_f)s
** - subos: sub-objects (t_s_o)s
**
** - handle references a point in space meant to 
**	facilitate object display and operations.
*/
typedef struct s_object	t_s_o;
struct						s_object
{
	t_s_ta			pnvs;
	t_s_ta			dots;
	t_s_ta			lnas;
	t_s_ta			fills;
	t_s_ta			subos;
	t_tag			handle;
	t_argb			argb;
	unsigned int	refs;
};

#endif
