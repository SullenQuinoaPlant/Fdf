#include "scene.h"
#include "functions.h"

int			main()
{
	t_xyz	ar[9] =
	{
		{1, 2, 3},
		{1, 2, 3},
		{1, 2, 3},
		{1, 2, 3},
		{1, 2, 3},
		{1, 2, 3},
		{1, 2, 3},
		{1, 2, 3},
		{1, 2, 3}
	};
	t_xyz	ret;

	barycenter(ar, 2, ret);
}
