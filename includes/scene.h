/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 04:35:47 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/08 04:35:48 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "outer.h"
# include "scene_typedefs.h"

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
**
**Within element-specific structures:
** - **ar: pointer to array of arrays.
** - ar_sz: number of allocated arrays.
** - nxt: list of next positions where to store new elements.
**		These list allocations are capped by TAG_NXT_CAP
*/

# define TAG_AR_CAP ((size_t)1 << 30)
# define TAG_NXT_CAP (DEF_TAG_AR_SZ / 4)
# define TAC TAG_AR_CAP
# define TNC TAG_NXT_CAP

# define TAG_POS_MASK ((t_tag)0xff)
# define TAG_POS_SHIFT 8 
# define TAG_AR_SZ ((size_t)1 << TAG_POS_SHIFT)
# define TPM TAG_POS_MASK 
# define TPS TAG_POS_SHIFT
# define TAS TAG_AR_SZ 

/*
**Scene elements hold a reference count in a (t_refct).
**Negative reference counts assigned to an object
**	indicate that we intend to release its tag.
*/
# define MAX_REFS INT_MAX

/*
**We use (t_argb)s to store color information on 4 bytes:
**0xALPHA;RED;GREEN;BLUE
*/

/*
**Different scene element types:
**
**NOTE :
**	- the reference count changing functions
**		rely on "refs" being the first 
**		structure member.
*/

enum						e_scene_element_groups
{
	e_spnv,
	e_sd,
	e_slna,
	e_sf,
	e_so,
	e_seg_sz,
	e_seg_null
};

# define X 0
# define Y 1
# define Z 2
/*
**T: θ, in (xOz) plane, from x
**P: φ, from y to (xOz) plane.
**Why choose θ and φ relative to y ?
**	there is no beacause axis.
**R: radius, from O.
*/
# define T 0
# define P 1
# define R 2
struct						s_point
{
	t_refct			refs;
	union
	{
		struct
		{
			double	xyz[3];
		}			cart;
		struct
		{
			double	xyz[3];
		};
	};
	union
	{
		struct
		{
			double	tpr[3];
		}			polr;
		struct
		{
			double	tpr[3];
		};
	};
};

struct						s_vector
{
	t_refct			refs;
	union
	{
		struct
		{
			double	xyz[3];
		}			cart;
		struct
		{
			double	xyz[3];
		};
	};
	union
	{
		struct
		{
			double	tpr[3];
		}			polr;
		struct
		{
			double	tpr[3];
		};
	};
};

/*
** points and vectors look the same in storage:
*/
union						u_spsv
{
	t_s_p	p;
	t_s_v	v;
};

/*
**Visible objects:
*/
struct						s_dot
{
	t_refct			refs;
	t_tag			pos_p;
	t_argb			argb;
};

/*
**lines are represented by their two extremities.
*/
# define L_END1 0
# define L_END2 1
struct						s_line
{
	unsigned int	refs;
	t_tag			ends[2];
	t_argb			argb[2];
};

/*
**arrows are vectors positioned in space.
*/
# define A_POS 0
# define A_VEC 1
struct						s_arrow
{
	t_refct			refs;
	t_tag			pnv[2];
	t_argb			argb[2];
};

union						u_slsa
{
	t_s_l	l;
	t_s_a	a;
};

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
struct						s_fill
{
	t_refct			refs;
	t_tag			vrt_p[3];
	t_argb			argb[3];
	t_tag			norm_v;
};
/*
**End of visible elements
*/

/*
**(t_s_o)s are collections of scene elements.
*/
struct						s_object_handle
{
	t_e_seg	type;
	t_tag	tag;
};

enum						e_object_element_groups
{
	e_op,
	e_ov,
	e_od,
	e_ol,
	e_oa,
	e_of,
	e_oo,
	e_oeg_sz,
	e_oeg_null
};

struct						s_object
{
	t_refct			refs;
	t_list			*e[e_oeg_sz];
	t_s_oh			hdl;
	t_argb			argb;
};

/*
**Scene control structures:
*/
struct						s_free_tags
{
	t_tag	free;
	t_tag	last;
};

/*
**(t_s_ta)s are used to find scene elements from tags,
**	just like (t_s_se)s.
**They aren't used to introduce elements to the scene
**	so do not need the 'nxt' list.
*/
struct						s_tagged_array
{
	void		**ar;
	size_t		ar_sz;
	size_t		e_sz;
};

/*
**'nxt' as in: next free tags.
**The (t_list) nxt is a list of (t_s_ft) structures.
*/
struct						s_scene_elements
{
	union
	{
		struct
		{
			void		**ar;
			size_t		ar_sz;
			size_t		e_sz;
		};
		t_s_ta	ta;
	};
	t_list		*nxt;
};

/*
**Coordinate transformation matrices are typedefed to:
**(t_pctrm) : point coordimante transform matrix
**(t_pctrmr) : point coordimante transform matrix row
**(t_s_pctr) : wraps the above in a struct, enables linking and chaining
**(t_pctr) as in: point coordinate transform, first arg most likely a (t_pctrm*)
*/

struct						s_points_coordinates_transform
{
	t_s_ring	ring;
	t_s_pctr	*prv;
	t_s_pctr	*nxt;
	t_pctrm		own_tr;
	t_pctrm		mashed_tr;
	int			view_ct;
};

/*
**Projections hold the shadows in the view plane of the points required
**	to describe scene elements.
**Point projections set to {max t_vuint, max t_vuint} indicate
**	the point may be out of the display array, and is expected to
**	cast multiple shadows.
*/
enum						e_view_projection_groups
{
	e_vpg,
	e_vdg,
	e_vlnag,
	e_vfg,
	e_vog,
	e_vpg_sz,
	e_vpg_null
};

/*
**Display coordinates are held in (t_vuint)s;
**	a type at least as big as view height and width
*/
# define V_H 0
# define V_W 1
/*
**(t_vuint)s are grouped by two in (t_vpos)s
*/

struct						s_point_projection
{
	t_vpos	point;
};

struct						s_dot_projection
{
	t_vpos	here;
};

struct						s_line_or_arrow_projection
{
	t_vpos	ends[2];
};

/*
**'tips_ct' gives the number of points used in 'tips'.
**'bar' : barycenter.
**There is one less side to the polygon than the count.
**Tips are required to be sorted by rotation around (bar; view-axis).
*/
struct						s_fill_projection
{
	t_vpos	tips[6];
	size_t	tips_ct;
	t_vpos	bar;
};

/*
**Object projection structures hold properties that may be set or unset
**	in each view.
**object flags:
*/
# define O_SHOW 0x1
# define O_HIGHLIGHT 0x2
struct						s_object_projection
{
	uint8_t	flags;
};

/*
**Projections, (t_proj)s, take point coordinates and an element,
**	and fill that element's projection structure in a scene.
**typedef void	(*t_pproj)(void*, t_u_spsv const *const, t_s_pp *);
**typedef void	(*t_dproj)(void*, t_u_spsv const *const, t_s_dp *);
**typedef void	(*t_loaproj)(void*, t_u_spsv const *const, t_s_loap *);
**typedef void	(*t_fproj)(void*, t_u_spsv const *const, t_s_fp *);
*/

/*
**Precendence 'prec' typically linked to depth, 
**	unless object is highlighted, in which case use 
**	negative values to indicate greater precedence.
*/
struct						s_pixel
{
	t_argb	argb;
	double	prec;
};

/*
**View builders are responsible for initializing:
** - proj
**
**The following fields are initialized by the scene:
** - ring
** - id
** - ao_cursor
**
**Abbreviations:
** - id: view  identification number.
** - s: scene.
** - ao: cursor on the scene's active object ring.
** - ct: coordinates transform.
** - vpnv: view points and vectors.
** - prj: projections. prj[i](prj_arg[i], ...) -> ve[i]
** - e: view elements.
** - h: view height.
** - w: view width.
** - v: view[h][w] of (t_s_pxl) to display.
**		v[0][0] : top left
**		v[0][w - 1] : top right
**		v[h - 1][0] : bottom left
**		v[h - 1][w - 1] : bottom right
*/
struct						s_scene_view
{
	t_s_ring	ring;
	int			id;
	t_s_s		*s;
	t_s_ao		*ao;
	t_s_pctr	*ct;
	t_u_spsv	**vpnv;
	t_proj		prj[e_vpg_sz];
	void		*prj_arg[e_vpg_sz];
	t_s_ta		e[e_vpg_sz];
	t_vuint		h;
	t_vuint		w;
	t_s_pxl		*view;
};

/*
**Scene:
*/
/*
**'vflags', (view flags) are the same as (t_s_op) flags.
*/
struct						s_active_object
{
	t_s_ring	ring;
	t_tag		tag;
	uint8_t		vlags;
};

/*
** - tar_allocs counts bytes allocated for tagged arrays.
** - nxt_allocs counts bytes allocated to t_list structures in (t_s_se)s.
** - e : scene elements
** - ao : active objects
** - ct : coordinate transforms
** - v : views
*/
struct						s_scene
{
	size_t		tar_allocs;
	size_t		nxt_allocs;
	t_s_se		e[e_seg_sz];
	t_s_ao		*ao;
	t_s_pctr	*ct;
	t_s_sv		*v;
};

# define RELEASING_TAG 1
# define REFCOUNT_TOO_BIG 2
# define REFCOUNT_INCOHERENT 3

#endif
