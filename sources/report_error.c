#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "outer.h"
#include "libft.h"

static void				our_errors(
	int err)
{
	char const *const	msgs[OUT_OF_VIEW] = {
		"bad argumentss\n",
		"memory cap\n",
		"bad input file\n",
		"out of view\n"};

	write(2, msgs[err - 1], ft_strlen(msgs[err - 1]));
}

static void				sys_error(
	void)
{
	perror("System error ");
}

void					report_error(
	int err)
{
	if (err > 0)
		our_errors(err);
	else
		sys_error();
}
