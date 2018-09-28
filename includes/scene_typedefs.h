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

# define DEF_TAG_POS_MASK ((t_tag)0xff)
# define DEF_TAG_POS_SHIFT 8 
# define DEF_TAG_AR_SZ ((size_t)1 << DEF_TAG_POS_SHIFT)

# define TAG_AR_CAP ((size_t)1 << 30)
# define TAC TAG_AR_CAP
# define TAG_NXT_CAP (DEF_TAG_AR_SZ / 4)

# define USPSV_TAG_POS_MASK (t_tag)0xffffU
# define USPSV_TAG_POS_SHIFT 16
# define USPSV_TAG_AR_SZ ((size_t)1 << USPSV_TAG_POS_SHIFT)

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

typedef struct				s_scene_points_and_vectors
{
	t_u_spsv	**ar;
	size_t		ar_sz;
	t_list		*nxt;
}							t_s_spnv;

typedef struct				s_scene_dots
{
	t_s_d	**ar;
	size_t	ar_sz;
	t_list	*nxt;
}							t_s_sd;

typedef struct				s_scene_lines_and_arrows
{
	t_u_slsa	**ar;
	size_t		ar_sz;
	t_list		*nxt;
}							t_s_slna;

typedef struct				s_scene_areas
{
	t_s_a	**ars;
	size_t	ar_sz;
	t_tag	nxt_tag;
}							t_s_sa;

typedef struct				s_scene_objects
{
	t_s_o	**ars;
	size_t	ar_sz;
	t_tag	nxt_tag;
}							t_s_so;

/*
**Scene projections own their own set of the scene points.
**The coordinates of these points are modified accoring to projection transform.
**Tags are used to identify points reliably accross point sets.
**Points should not be deleted from projections: change scene set, then update.
*/
/*
**t_pctr as in: point coordinate transform
*/
typedef void (*	t_pctr)(void*, t_s_p**, size_t, t_s_p**);
typedef struct				s_projection
{
	t_s_prj			*up;
	t_pctr			tr;
	t_s_p			**tr_res;
	void			*tr_arg;
	size_t			tr_arg_sz;
	int				refs;
}							t_s_prj;

/*
**event key:
*/
typedef SOMETHING	t_ekey;
typedef int (*	t_ehandler)(t_ekey, t_s_v*, t_s_s*, void*);

typedef struct s_view		t_s_v;
struct						s_view
{
	t_s_prj		*proj;
	t_ehandler	ehdl;
	void		*state;
	t_s_sv		*nxt;
	t_s_sv		*prv;
};

/*
** - ar_allocs counts bytes
** - nxt_allocs counts individual allocs not bytes.
*/
typedef struct				s_scene
{
	size_t		ar_allocs;
	size_t		nxt_allocs;
	t_s_spnv	pnvs;
	t_s_slna	lnas;
	t_s_so		os;
	t_s_prj		nullproj;
	t_s_sv		*views;
}							t_s_s;

typedef int	(*t_scene_builder)(t_s_sbi*, t_s_s*);
typedef int	(*t_tssbi_freer)(t_s_sbi*);

#endif
