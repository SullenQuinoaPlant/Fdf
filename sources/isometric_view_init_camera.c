#include "functions.h"
#include "scene.h"

#define COS_PI_2 0.0
#define SIN_PI_2 1.0
#define SIN_PI_4 0xb.504f333f9de6485p-4
#define COS_PI_4 0xb.504f333f9de6484p-4
#define SQRT_2 0xb.504f333f9de6484p-3
#define SQRT_3 0xd.db3d742c265539ep-3

/*
**Default rotations:
** 3/4Pi around z
** -1/2Pi - arcsin(1/sqrt(3)) around yawed x.
*/

t_s_pctr					*add_isometric_camera(
	t_zntr zntr,
	t_s_s *s)
{
	t_pctrm const	cts[CYRPZ] = {
		{{-SIN_PI_4, COS_PI_4, 0},
		{COS_PI_4, -SIN_PI_4, 0},
		{0, 0, 1},
		{0, 0, 0}},
		{{1, 0, 0},
		{0, 1.0 / SQRT_3, -SQRT_2 / SQRT_3},
		{0, SQRT_2 / SQRT_3, 1.0 / SQRT_3},
		{0, 0, 0}},
		{{1, 0, 0},
		{0, 1, 0},
		{0, 0, 1},
		{0, 0, 0}},
		{{zntr[TRZ_Z], 0, 0},
		{0, zntr[TRZ_Z], 0},
		{0, 0, zntr[TRZ_Z]},
		{zntr[TRZ_TR + X], zntr[TRZ_TR + Y], zntr[TRZ_TR + Z]}}};

	return (add_camera(cts, CYRPZ, &s->ct));
}
