#ifndef PARSE_TYPEDEFS_H
# define PARSE_TYPEDEFS_H

typedef t_s_cxyd	(*t_cdgfxyrz)[][1];

typedef enum e_scene_input_types	t_e_sit;

typedef struct s_cartesian_dot_grid_fullxy_regularz	t_s_cdgfxyrz;

typedef int		(*t_scene_builder)(t_s_sbi*, t_s_s*);

typedef int		(*t_tssbi_freer)(t_s_sbi*);

typedef struct s_cartesian_xy_dot	t_s_cxyd;

typedef struct s_scene_builder_input	t_s_sbi;

#endif
