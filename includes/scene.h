/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 04:35:47 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/15 06:26:06 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include <limits.h>

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
# define TAG_POS_MASK ((t_tag)0xff)
# define TAG_POS_SHIFT 8 
# define TAG_AR_SZ ((size_t)1 << TAG_POS_SHIFT)
# define TPM TAG_POS_MASK 
# define TPS TAG_POS_SHIFT
# define TAS TAG_AR_SZ 

# define TAG_AR_CAP ((size_t)1 << 30)
# define TAG_NXT_CAP (TAG_AR_SZ / 4)
# define TAC TAG_AR_CAP
# define TNC TAG_NXT_CAP

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
# define ARGBS 4
# define A 0
# define R 1
# define G 2
# define B 3
# define ARGB_MASK 0xff
# define ARGB_BYTE 0xff

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
 **T: θ, in (xOy) plane, from x
 **P: φ, from z to (xOy) plane.
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
	t_tag			pos;
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
**	these matrix have DIMS_N_TR rows (one per axis and one for translations)
**(t_pctrmr) : point coordimante transform matrix row
**(t_s_pctr) : wraps the above in a struct, enables linking and chaining
**(t_pctr) as in: point coordinate transform, first arg most likely a (t_pctrm*)
*/
# define DIMS_N_TR 4

struct						s_point_coordinates_transform
{
	t_s_ring	ring;
	int			refs;
	t_s_pctr	*prv;
	t_s_pctr	*nxt;
	t_pctrm		own;
	t_pctrm		mashed;
};

/*
 **Projections hold the shadows in the view plane of the points required
 **	to describe scene elements.
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
# define TVUINT_MAX UINT_MAX
# define V_H 0
# define V_W 1
# define V_DIMS VIEW_DIMS

/*
 **In projection objects :
 **Precendence 'prec' typically linked to depth,
 **Flag:
 **	- visibility
 */
struct						s_point_projection
{
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

# define F_V_VISIBLE 0x01
struct						s_dot_projection
{
	uint32_t	flgs
	t_vpos		here;
	t_argb		argb;
	double		prec;
};

struct						s_line_or_arrow_projection
{
	uint32_t	flgs;
	t_vpos		ends[2];
	t_argb		argb[2];
	double		prec[2];
};

/*
 **'tips_ct' gives the number of points used in 'tips'.
 **'bar' : barycenter.
 **There is one less side to the polygon than the count.
 **Tips are required to be sorted by rotation around (bar; view-axis).
 */
struct						s_fill_projection
{
	uint32_t	flgs;
	t_vpos		tips[6];
	t_argb		argb[6];
	size_t		tips_ct;
	t_vpos		bar;
};

/*
**Object projection structures hold properties that may be set or unset
**	in each view.
**
**'set_flgs' and 'un_flgs' can be used to force flag values, otherwise
**	compied from (t_s_o). The values are used as so:
**		flags |= set_flgs
**		flags &= un_flgs
*/
struct						s_object_projection
{
	uint8_t	set_flgs;
	uint8_t	un_flgs;
};

/*
 **Projections, (t_proj)s, take point coordinates and an element,
 **	and fill that element's projection structure in a scene.
 **typedef void	(*t_pproj)(t_s_sv*, void*, t_u_spsv const *const *, t_s_pp *);
 **typedef void	(*t_dproj)(t_s_sv*, t_s_d*, t_u_spsv const *const *, t_s_dp *);
 **typedef void	(*t_loaproj)(
 **	t_s_sv*, t_u_slsa*, t_u_spsv const *const *, t_s_loap *);
 **typedef void	(*t_fproj)(
 **	t_s_sv*, t_s_f*, t_u_spsv const *const *, t_s_fp *);
 */

struct						s_pixel
{
	t_argb	argb;
	double	prec;
};

/*
 **Each view has its coordinates system.
 **	The x axis is taken along the view width, from left to right.
 **	The y axis is taken along the view height, from top to bottom.
 **	The z axis is in the away direction from the viewpoint.
 **	This system's origin is the view center.
 **		If view height or width are even integers, the center is shifted
 **			towards bottom right so that the coordinates of a point (x, y)
 **			can be obtained by adding as so:
 **				((t_vuint)(x + (double)(w / 2)), (t_vuint)(y + (double)(h / 2)))
 **
 **The position of the 'id' field, first after the t_s_ring header, is relied upon
 **	for initialization purposes.
 **
 **The following fields are initialized by the scene:
 ** - ring
 ** - id
 ** - ao_cursor
 ** - (t_s_ta) array e (not the tar content)
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
 ** - pxl : pointer to array of t_argbs to display
 ** - pxl_prec : pointer to array of same dimensions as 'pxl' holds each pixel's
 **	current precedence.
 **		pxl[0][0] : top left
 **		pxl[0][w - 1] : top right
 **		pxl[h - 1][0] : bottom left
 **		pxl[h - 1][w - 1] : bottom right
 */
struct						s_scene_view
{
	t_s_ring	ring;
	int			id;
	t_s_s		*s;
	t_s_ao		*ao;
	t_s_pctr	*ct;
	t_proj		prj[e_seg_sz];
	t_s_ta		e[e_seg_sz];
	t_vuint		h;
	t_vuint		w;
	t_argb		*pxl;
	double		*pxl_prec;
	int			out_fd;
	void		*out_wdw;
};

/*
**Scene:
*/
# define O_SHOW 0x1
# define O_HIGHLIGHT 0x2
struct						s_active_object
{
	t_s_ring	ring;
	t_tag		tag;
	uint8_t		flgs;
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
