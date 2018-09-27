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
