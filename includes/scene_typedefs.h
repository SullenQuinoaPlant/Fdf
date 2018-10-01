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
**TAG_POS_SHIFT used to shift out intra-array position bits.
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
# define TAG_AR_SZ ((size_t)1 << TAG_POS_SHIFT)

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

typedef enum				e_scene_element_groups
{
	e_spnv,
	e_sd,
	e_slna,
	e_sf,
	e_so,
	e_seg_sz,
	e_seg_null
}							t_e_seg;

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
**count are used.
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
	t_s_oh			hdl;
	t_argb			argb;
}							t_s_o;
/*
**End scene elements.
*/

/*
**Scene control structures:
*/

typedef struct				s_free_tags
{
	t_tag	free;
	t_tag	last;
}							t_s_ft;

/*
**The (t_list) nxt is a list of (t_s_ft) structures.
*/
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
typedef void	(*t_pctr)(void*, size_t, t_u_spsv const**, t_u_spsv**);

/*
**(t_s_cs)s own their own set of the scene points.
**The coordinates of these points are modified from the previous (t_s_c),
**		with the (t_pctr) tr.
**Tags are used to identify points reliably accross point coordinate sets.
**A (t_s_cs)'s points should always be the result of applying a (t_s_pc)'s
**	(t_pctr) transform to the previous set of point coordinates.
**	For any other change, go through root scene structure.
*/

# define IS_UPDATED 0x1
typedef struct s_point_coordinates	t_s_pc;
struct						s_points_coordinates
{
	t_s_ring	linked;
	t_s_pc		*prv;
	t_s_pc		*nxt;
	int			refs;
	uint8_t		flags;
	t_pctr		tr;
	void		*tr_arg;
	t_u_spsv	**pnv;
}

/*
**Projections hold the shadows of the points required
**	to describe scene elements in space, on a 2d plane.
**Points themselves are not represented, so points are
**	not projected, and points have no shadows. (they are evil)
*/
typedef enum				e_view_projections
{
	e_vd,
	e_vlna,
	e_vf,
	e_vo,
	e_vp_sz,
	e_vp_null
}							t_e_vp;

/*
**A signed type at least as big as view height and width
*/
typedef int	t_vint;

# define V_H 0
# define V_W 1

typedef t_vint	(t_vpos)[2]

typedef struct				s_dot_projection
{
	t_vpos	here;
}							t_s_dp;

typedef struct				s_line_or_arrow_projection
{
	t_vpos	between[2];
}							t_s_loap;

/*
**'count' gives the number of points used in 'inside'.
**There is one less side to the polygon than the count.
**'bar' : barycenter.
*/
typedef struct				s_fill_projection
{
	t_vpos	inside[6];
	t_vpos	bar;
	size_t	count;
}							t_s_fp;

/*
**object flags:
*/
# define SHOW_O 0x1
# define HIGHLIGHT_O 0x2
typedef struct				s_object_projection
{
	uint8_t	flags;
}							t_s_op;

**(t_s_vp) : typedef struct view projections
**Reuse projections are stored with tags in exactly the same way
**	scene elements are:
**All assignments are done through scene, t_s_sv has no need for:
** - nxt
** - ar_sz
*/
typedef struct				s_view_projected_elements
{
	void		**ar;
	size_t		e_sz;
}							t_s_vpe;

/*
**projection: takes point coordinates and element groups and
**	spits out each group's projection.
**Does not allocate (t_s_vp)s, stores stuff in them.
/*
typedef void	(*t_proj)(void*, t_s_s*, t_s_pc const*, t_s_vp const*const);
typedef void	(*t_dproj)(void*, t_s_s*, t_s_pc const*, t_s_dp *const);
typedef void	(*t_loaproj)(void*, t_s_s*, t_s_pc const*, t_s_loap *const);
typedef void	(*t_fproj)(void*, t_s_s*, t_s_pc const*, t_s_fp *const);

/*
**The active object ring lives in the scene structure.
**But each view has a pointer to it.
*/
typedef struct s_active_object	t_s_ao;

/*
**View builders are responsible for initializing:
** - proj
** - all event functions
** - stuff, stuff_sz, stuff_del
**
**The following fields are initialized by the scene:
** - ring
** - id
** - ao_cursor
*/
typedef struct s_view		t_s_v;
struct						s_view
{
	t_s_ring	ring;
	t_s_s		*scene;
	int			id;
	t_s_pc		*points;
	t_proj		prj;
	t_s_vp		es[e_vp_sz];
	t_s_ao		*ao_cursor;
};

/*
**Scene:
*/
typedef struct				s_active_object
{
	t_s_ring	ring;
	t_tag		tag;
	uint8_t		flags;
}							t_s_ao;

/*
** - tar_allocs counts bytes allocated for tagged arrays.
** - nxt_allocs counts bytes allocated to t_list structures.
*/
typedef struct				s_scene
{
	size_t		tar_allocs;
	size_t		nxt_allocs;
	t_s_se		es[e_eg_sz];
	t_s_ao		*ao;
	t_s_sprj	prjs;
	t_s_sv		*views;
}							t_s_s;

typedef int		(*t_scene_builder)(t_s_sbi*, t_s_s*);
typedef int		(*t_tssbi_freer)(t_s_sbi*);

#endif
