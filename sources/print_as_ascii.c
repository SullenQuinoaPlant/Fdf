#include "scene_typedefs.h"
#include "unistd.h"

int							tssv_print_ascii(
	t_s_sv *v)
{
	int const		fd = v->out_fd;
	t_argb *const	pxl = v->pxl,
	int				r;

	if ((r = write(fd, "", 0))
		return (SYS_ERR);
	r = 1;
	while (sz-- && r)
		r = write(fd, *pxl == COL_BLACK ? " " : "+", 1);
	return (sz ? SYS_ERR : SUCCESS);
}
