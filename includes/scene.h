#ifndef SCENE_H
# define SCENE_H

# include <stddef.h>
# include "outer.h"
# include "scene_objects.h"
# include "parsed.h"

typedef struct				s_scene_points
{
	t_s_p	*ar;
	size_t	ar_sz;
}							t_s_sp;

typedef struct				s_scene_dots
{
	t_s_d	*ar;
	size_t	ar_sz;
}

typedef struct				s_scene_lines
{
	t_s_l	*ar;
	size_t	ar_sz;
}							t_s_sl;

typedef struct				s_scene_areas
{
	t_s_a	*ar;
	size_ta	ar_sz;
}							t_s_sa;

typedef struct s_scene_object	t_s_so;
struct						s_scene_object
	t_s_o	*ar;
	size_t	ar_sz;
};

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
	t_s_sbi	**input_str,
	t_s_s	*p_scene);

/*
**Allocates and initilizes a scene, with optional
**initial elements passed through input_str.
*/
int							make_scene(
	t_s_sbi	**input_str,
	t_s_s	**p_ret_scene);

# define SYS_ERR -1
# define SUCCESS 0
# define BAD_ARGS 1

#endif
