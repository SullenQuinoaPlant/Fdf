#ifndef SCENE_TYPEDEFS_H
# define SCENE_TYPEDEFS_H

# include "outer.h"

/*
**Scene elements are stored in array of a defined size.
**Most significant bits of tags are used to
**	index a dynamically allocated array of these arrays.
**Least significant bits give tagged element position within array.
**
**Memory allocation for these arrays is capped.
**	see TAG_AR_CAP
**
**TAG_POS_MASK used to retrieve intra-array position.
**TAG_AR_SHIFT used to shift out intra-array position bits.
**TAG_AR_SZ is determined by TAG_AR_SHIFT
**
**NOTE :
**The TAG defines may be adjusted per element type.
**See scene_objects.h (u_spsv TAGs, for example, differ from default)
**
**
**Within element-specific structures:
** - **ar: pointer to array of arrays.
** - ar_sz: number of allocated arrays.
** - nxt: list of next positions where to store new elements.
**		These list allocations are capped by TAG_NXT_CAP
*/

typedef unsigned int	t_tag;

# define TAG_POS_MASK ((t_tag)0xff)
# define TAG_POS_SHIFT 8 
# define TAG_AR_SZ ((size_t)1 << DEF_TAG_POS_SHIFT)

# define TPM TAG_POS_MASK 
# define TPS TAG_POS_SHIFT
# define TAS TAG_AR_SZ 

# define TAG_AR_CAP ((size_t)1 << 30)
# define TAG_NXT_CAP (DEF_TAG_AR_SZ / 4)
# define TAC TAG_AR_CAP
# define TNC TAG_NXT_CAP

/*
**used to store colors :
**0xALPHA;RED;GREEN;BLUE
*/
typedef uint32_t	t_argb;


/*
**Different scene element types:
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

# define T 0
# define P 1
# define R 2

typedef struct				s_point
{
	unsigned int	refs;
	union
	{
		struct cart
		{
			double	xyz[3];
		};
		struct
		{
			double	xyz[3];
		};
	};
	union
	{
		struct polr
		{
			double	tpr[3];
		};
		struct
		{
			double	tpr[3];
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
			double	xyz[3];
		};
		struct
		{
			double	xyz[3];
		};
	};
	union
	{
		struct polr
		{
			double	tpr[3];
		};
		struct
		{
			double	tpr[3];
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
**Array of tags that are part of an object.
**count are used, from index 0.
**array size in bytes is : sz * TAG_SZ.
**May have trailing unused tag slots.
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

/*
**(t_s_o)s are collections of basic elements.
**They can be displayed.
*/
typedef struct				s_object
{
	unsigned int	refs;
	t_s_ta			es[e_eg_sz]
	t_handle		h;
	t_argb			argb;
}							t_s_o;
/*
**End visual elements.
*/

/*
**Scene control structures:
*/

typedef struct				s_free_tags
{
	t_tag	free;
	t_tag	last;
}							t_s_ft;

typedef struct				s_scene_elements
{
	void		**ar;
	size_t		ar_sz;
	size_t		e_sz;
	t_list		*nxt;
}							t_s_se;

/*
**t_pctr as in: point coordinate transform
*/
typedef void	(*t_pctr)(void*, size_t, t_s_p**);

/*
**Scene projections own their own set of the scene points.
**The coordinates of these points are modified.
**Tags are used to identify points reliably accross point sets.
**Projections points should not be modified;
**	instead, change scene points then update.
*/

typedef struct				s_projection
{
	int			refs;
	t_s_prj		*up;
	t_pctr		tr;
	t_u_spsv	**pnv;
	void		*stuff;
}							t_s_prj;

/*
**p_tsprj is a list of >pointers< to (t_s_prj) structures.
*/
typedef struct				s_scene_projections
{
	t_s_prj		nullproj;
	t_list		*p_tsprj;
}							t_s_sprj;

/*
**t_s_so flags:
*/
# define SHOW_O 0x1
# define HIGHLIGHT_O 0x2
typedef struct				s_active_object
{
	t_s_ring	ring;
	t_tag		tag;
	uint8_t		flags;
}							t_s_ao;

/*
**Views have their own set of the scene objects ring.
**View builders are responsible for initializing:
** - proj
** - all event functions
** - stuff, stuff_sz, stuff_del
**
**The following fields are initialized by the scene:
** - ring
** - id
** - ao
** - ao_cursor
*/
typedef struct s_view		t_s_v;
struct						s_view
{
	t_s_ring	ring;
	int			id;
	t_s_prj		*proj;
	t_s_ao		*ao;
	t_s_ao		*ao_cursor;
	MLX_WINDOW
	MLX_IMAGE
	int			(*on_expose)(void*);
	int			(*on_key)(int, void*);
	int			(*on_mouse)(int, int, int, void*);
	int			(*on_loop)(void*);
	void		*stuff;
	size_t		stuff_sz;
	void		(*stuff_del)(void*, size_t);
};

/*
** - ar_allocs counts bytes
** - nxt_allocs counts individual allocs not bytes.
*/
typedef struct				s_scene
{
	size_t		ar_allocs;
	size_t		nxt_allocs;
	t_s_se		es[e_eg_sz];
	t_s_ao		*ao;
	t_s_sprj	prjs;
	t_s_sv		*views;
}							t_s_s;

typedef int		(*t_scene_builder)(t_s_sbi*, t_s_s*);
typedef int		(*t_tssbi_freer)(t_s_sbi*);

#endif
