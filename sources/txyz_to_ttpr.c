#include <math.h>
#include "scene.h"

void						txyz_to_ttpr(
	t_xyz const in,
	t_tpr out)
{
	double const	x = in[X];
	double const	y = in[Y];
	double const	z = in[Z];
	double			r;

	out[T] = atan2(y, x);
	r = sqrt(x * x + y * y + z * z);
	out[R] = r;
	out[P] = acos(z / r);
}
