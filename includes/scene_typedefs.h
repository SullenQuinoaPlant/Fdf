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

typedef enum				e_scene_element_groups
{
	e_spnv,
	e_sd,
	e_slna,
	e_sa,
	e_so,
	e_seg_sz
}							t_e_seg;

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
	t_s_p		**pnv;
	void		*stuff;
}							t_s_prj;

typedef struct				s_scene_projections
{
	t_s_prj		nullproj;
	t_s_prj		*ar;
	size_t		ar_sz;
}							t_s_sprj;

typedef struct s_view		t_s_v;
struct						s_view
{
	int			id;
	t_s_sv		*nxt;
	t_s_sv		*prv;
	t_s_prj		*proj;
	void		*state;
	int (		*on_expose)(void*);
	int (		*on_key)(int, void*);
	int (		*on_mouse)(int, int, int, void*);
	int (		*on_loop)(void*);
};

/*
** - ar_allocs counts bytes
** - nxt_allocs counts individual allocs not bytes.
*/
typedef struct				s_scene
{
	size_t		ar_allocs;
	size_t		nxt_allocs;
	t_s_se		es[e_seg_sz];
	t_s_sprj	prjs;
	t_s_sv		*views;
}							t_s_s;

typedef int		(*t_scene_builder)(t_s_sbi*, t_s_s*);
typedef int		(*t_tssbi_freer)(t_s_sbi*);

#endif
