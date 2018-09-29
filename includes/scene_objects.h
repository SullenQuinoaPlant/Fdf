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

typedef enum				e_element_groups
{
	e_pnvg,
	e_dg,
	e_lnag,
	e_ag,
	e_og,
	e_eg_sz,
	e_eg_null
}							t_e_eg;

/*
**s_point describes a point in space.
*/

# define X 0
# define Y 1
# define Z 2

typedef struct				s_point
{
	unsigned int	refs;
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
}							t_s_p;

typedef struct				s_vector
{
	unsigned int	refs;
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
	unsigned int	refs;
	t_tag			pos_p;
	t_argb			argb;
}							t_s_d;

/*
**lines are represented by two extremities; they
**	are finite segments (but letter 's' already used).
*/
# define L_END1 0
# define L_END2 1
typedef struct				s_line
{
	unsigned int	refs;
	t_tag			end_p[2];
	t_argb			argb[2];
}							t_s_l;
/*
**arrows are vectors positioned in space.
*/
# define A_POS 0
# define A_VEC 1
typedef struct				s_arrow
{
	unsigned int	refs;
	t_tag			pnv[2];
	t_argb			argb[2];
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
	unsigned int	refs;
	t_tag			vrt_p[3];
	t_argb			argb[3];
	t_tag			norm_v;
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

typedef struct				s_object_handle
{
	t_e_eg	type;
	t_tag	tag;
}							t_s_oh;

typedef struct				s_object
{
	unsigned int	refs;
	t_s_ta			es[e_eg_sz]
	t_handle		h;
	t_argb			argb;
}							t_s_o;

#endif
