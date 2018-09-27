#ifndef SCENE_H
# define SCENE_H

# include <stddef.h>
# include "outer.h"
# include "scene_objects.h"
# include "parsed.h"

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

# define DEF_TAG_POS_MASK ((t_tag)0xff)
# define DEF_TAG_POS_SHIFT 8 
# define DEF_TAG_AR_SZ ((size_t)1 << DEF_TAG_POS_SHIFT)

# define TAG_AR_CAP ((size_t)1 << 30)
# define TAC TAG_AR_CAP
# define TAG_NXT_CAP (DEF_TAG_AR_SZ / 4)

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

typedef struct				s_scene_lines
{
	t_s_l	**ar;
	size_t	ar_sz;
	t_list	*nxt;
}							t_s_sl;

typedef struct				s_free_scene_lines
{
	t_s_sl	*free;
	t_s_sl	*last;
}							t_s_fsl;

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

/*
**functions:
*/
/*
**In add_tssbis_to_scene:
** (t_s_sbi) string array is freed by function call.
** Will fail if pointer to string is not properly initialized.
*/
int							add_tssbis_to_scene(
	t_s_sbi	*input_str,
	t_s_s	*p_scene);

void						free_spnv(
	t_s_spnv *points);

void						free_tssa(
	t_s_sa *areas);

void						free_tssbi_str(
	t_s_sbi	*str);

void						free_tssd(
	t_s_sd *dots);

void						free_tssl(
	t_s_sl *lines);

void						free_tsso(
	t_s_so *objects);

int							get_nxt_uspsv(
	t_s_s		*scene,
	t_u_spsv	**p_ret);

int							init_spnv(
	t_s_spnv *p);

/*
**Allocates and initilizes a scene, with optional
**initial elements passed through input_str.
**If input_str is not null, make_scene always frees the contents.
*/
int							make_scene(
	t_s_sbi	*input_str,
	t_s_s	**p_ret_scene);

void						scene_teardown(
	t_s_s	**scene);

#endif
