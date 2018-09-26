#include "scene.h"

int					scene_builder_empty(
	t_s_sbi *sbi,
	t_s_s *scene)
{
	(void)sbi;
	(void)scene;
	return (SUCCESS);
}

int					scene_builder_cdgfxyrz(
	t_s_sbi *sbi,
	t_s_s *scene)
{
	t_s_cdgfxyrz *const	grid = (t_s_cdgfxyrz*)sbi->input;
	t_s_cxyd 			(*const ar)[grid->y_sz] = &grid->ar;
	size_t				i;

	i = -1;
	while (++i < grid->x_sz)
	
}
