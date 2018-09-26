#ifndef SCENE_H
# define SCENE_H

# include <stddef.h>
# include "outer.h"
# include "scene_objects.h"
# include "parsed.h"

/*
**Scene elements are stored in array of a defined size.
**Least significant bits of tags are used to
**	index a dynamically allocated array of these arrays.
**Most significant bits identify give tagged element position within array.
**
**NOTE : in t_s_p, t_s_d, t_s_d, t_s_o:
**	only the in-array position bits are stored,
**	pre-shifted.
**
** - **ars: pointer to array of arrays.
** - ar_count: number of allocated arrays.
** - nxt_tag: next position where to store a new element.
**
**AR_MASK used to retrieve array number.
**POS_SHIFT used to shift out array number,
**	get position within array.
**AR_SZ is determined by t_tag type size and mask
*/

# define TAG_AR_MASK (t_tag)0xffff
# define TAG_POS_SHIFT 16 
# define TAG_AR_SZ ((~(t_tag)0) >> POS_SHIFT) + 1

/*
**
typedef struct				s_scene_points
{
	t_s_p	**ar;
	size_t	ar_sz;
	t_tag	nxt_tag;
}							t_s_sp;

typedef struct				s_scene_dots
{
	t_s_d	**ar;
	size_t	ar_sz;
	t_tag	nxt_tag;
}

typedef struct				s_scene_lines
{
	t_s_l	**ars;
	size_t	ar_sz;
	t_tag	nxt_tag;
}							t_s_sl;

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
	t_s_sp	points;
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

void						free_tssbi_str(
	t_s_sbi	*str);

void						init_tsp_ar(
	t_s_p	*ar);

int							init_tssp(
	t_s_sp	*p);

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

void						tssp_free(
	t_s_sp *points);

# define SYS_ERR -1
# define SUCCESS 0
# define BAD_ARGS 1

#endif
