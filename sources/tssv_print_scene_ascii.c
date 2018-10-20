#include <unistd.h>
#include "scene.h"
#include "colors.h"

int							tssv_print_ascii(
	t_s_sv *v)
{
	int const		fd = v->out_fd;
	t_argb *const	lim = v->pxl + v->w * v->h;
	t_argb			*pxl;
	int				r;

	if ((r = write(fd, "", 0)))
		return (SYS_ERR);
	pxl = v->pxl;
	r = 1;
	while (pxl < lim && r)
		r = write(fd, *pxl++ == COL_BLACK ? " " : "+", 1);
	return (pxl < lim ? SYS_ERR : SUCCESS);
}
