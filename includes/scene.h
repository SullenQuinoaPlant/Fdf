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
** - **ars: pointer to array of arrays.
** - ar_count: number of allocated arrays.
** - nxt_tag: next position where to store a new element.
**
**TAG_AR_MASK used to retrieve array number.
**TAG_POS_SHIFT used to shift out array number,
**	and get position within array.
**TAG_AR_SZ is determined by t_tag type size and mask
*/

# define TAG_AR_MASK (t_tag)0xffff
# define TAM TAG_AR_MASK
# define TAG_POS_SHIFT 16 
# define TPS TAG_POS_SHIFT
# define TAG_AR_SZ ((~(t_tag)0) >> POS_SHIFT) + 1
# define TAS TAG_AR_SZ

typedef struct s_free_scene_points	t_s_fsp;
typedef struct				s_scene_points
{
	t_s_p	**ar;
	size_t	ar_sz;
	t_list	*nxt;
}							t_s_sp;

/*
**(t_s_fsp)s are stored in nxt list of (t_s_sp)
*/
typedef struct				s_free_scene_points
{
	t_s_sp	*free;
	t_s_sp	*last;
}							t_s_fsp;

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

void						free_tssp(
	t_s_sp *points);

int							get_nxt_p(
	t_s_s	*scene,
	t_s_p	**p_ret);

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

# define SYS_ERR -1
# define SUCCESS 0
# define BAD_ARGS 1

#endif
