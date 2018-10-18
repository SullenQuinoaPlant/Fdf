#include <math.h>
#include "scene.h"

void						txyz_to_ttpr(
	t_xyz const in,
	t_tpr out)
{
	double const	x = in[x];
	double const	y = in[y];
	double			r;

	out[t] = atan2(y, x);
	r = sqrt(x * x + y * y + z * z);
	out[r] = r;
	out[p] = acos(z / r);
}
