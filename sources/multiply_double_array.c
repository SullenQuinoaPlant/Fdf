#include "outer.h"

void					mult_dbl_ar(
	double mult,
	size_t sz,
	double *ar)
{
	double *const	lim = ar + sz;

	while (ar < lim)
		*(ar++) *= mult;
}
