#ifndef CDGFXYRZ_BUILDER_H
# define CDGFXYRZ_BUILDER_H

# include "scene.h"

typedef int (*	t_line_adder)(t_s_cdgfxyrz*, t_tag*, t_s_s*, t_s_o*);

int							cdgfxyrz_add_lines(
	t_s_cdgfxyrz	*p,
	t_tag			*tags,
	t_s_s			*scene,
	t_s_o			*object);
#endif
