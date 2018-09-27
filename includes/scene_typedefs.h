#ifndef SCENE_TYPEDEFS_H
# define SCENE_TYPEDEFS_H

# include "outer.h"

/*
**Scene elements are stored in array of a defined size.
**Most significant bits of tags are used to
**	index a dynamically allocated array of these arrays.
**Least significant bits give tagged element position within array.
**
**Allocations system calls for these arrays is capped.
**See TAG_AR_CAP
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
**	These list allocations are capped by TAG_NXT_CAP
*/

typedef unsigned int	t_tag;

# define DEF_TAG_POS_MASK ((t_tag)0xff)
# define DEF_TAG_POS_SHIFT 8 
# define DEF_TAG_AR_SZ ((size_t)1 << DEF_TAG_POS_SHIFT)

# define TAG_AR_CAP ((size_t)1 << 30)
# define TAC TAG_AR_CAP
# define TAG_NXT_CAP (DEF_TAG_AR_SZ / 4)

/*
**used to store colors :
**0xRED;GREEN;BLUE;ALPHA
*/
typedef uint32_t	t_rgba;

typedef struct				s_scene_points_and_vectors
{
	t_u_spsv	**ar;
	size_t		ar_sz;
	t_list		*nxt;
}							t_s_spnv;

typedef struct				s_free_points_and_vectors
{
	t_u_spsv	*free;
	t_u_spsv	*last;
}							t_s_fpnv;

typedef struct				s_scene_dots
{
	t_s_d	**ar;
	size_t	ar_sz;
	t_list	*nxt;
}

typedef struct				s_free_scene_dots
{
	t_s_sd	*free;
	t_s_sd	*last;
}							t_s_fsd;

typedef struct				s_scene_lines_and_arrows
{
	t_u_slsa	**ar;
	size_t		ar_sz;
	t_list		*nxt;
}							t_s_slna;

typedef struct				s_free_lines_and_arrows
{
	u_t_slsa	*free;
	u_t_slsa	*last;
}							t_s_flna;

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

typedef struct				s_scene
{
	size_t		ar_allocs;
	size_t		nxt_allocs;
	t_s_spnv	pnvs;
	t_s_sd	dots;
	t_s_sl	lines;
	t_s_sa	areas;
	t_s_so	objects;
}							t_s_s;

typedef int	(*t_scene_builder)(t_s_sbi*, t_s_s*);
typedef int	(*t_tssbi_freer)(t_s_sbi*);

#endif
