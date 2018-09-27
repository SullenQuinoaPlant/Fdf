#ifndef SCENE_FUNCTIONS_H
# define SCENE_FUNCTIONS_H

# include "scene.h"

/*
**In add_tssbis_to_scene:
** (t_s_sbi) string array is freed by function call.
** Will fail if pointer to string is not properly initialized.
*/
int							add_tssbis_to_scene(
	t_s_sbi	*input_str,
	t_s_s	*p_scene);

void						free_slna(
	t_s_slna	*p);

void						free_spnv(
	t_s_spnv	*p);

void						free_tssbi_str(
	t_s_sbi	*str);

int							init_slna(
	t_s_slna	*p);

int							init_spnv(
	t_s_spnv	*p);

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
