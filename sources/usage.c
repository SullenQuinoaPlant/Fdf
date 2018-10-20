#include <unistd.h>
#include "outer.h"

#define USAGE "usage: ./fdf path-to-conforming-file\n"

int								usage(
	void)
{
	int const	len = ft_strlen(USAGE);
	int			r;

	if ((r = write(1, USAGE, ft_strlen(USAGE))) != len)
		return (SYS_ERR);
	return (SUCCESS);
}
