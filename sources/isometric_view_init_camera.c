#include "functions.h"
#include "scene.h"

#define SIN_PI_4 0xb.504f333f9de6485p-4
#define COS_PI_4 0xb.504f333f9de6484p-4
#define SQRT_2 0xb.504f333f9de6484p-3
#define SQRT_3 0xd.db3d742c265539ep-3

t_s_pctr					*add_isometric_camera(
	t_zntr zntr,
	t_s_s *s)
{
	t_pctrm const	cts[CYRPZ] = {
		{{COS_PI_4, SIN_PI_4, 0},
		{-SIN_PI_4, COS_PI_4, 0},
		{0, 0, 1},
		{0, 0, 0}},
		{{1, 0, 0},
		{0, 1, 0},
		{0, 0, 1},
		{0, 0, 0}},
		{{SQRT_2 / SQRT_3, 0, 1.0L / SQRT_3},
		{0, 1, 0},
		{-1.0L / SQRT_3, 0, SQRT_2 / SQRT_3},
		{0, 0, 0}},
		{{zntr[TRZ_Z], 0, 0},
		{0, zntr[TRZ_Z], 0},
		{0, 0, zntr[TRZ_Z]},
		{zntr[TRZ_TR + X], zntr[TRZ_TR + Y], zntr[TRZ_TR + Z]}}};

	return (add_camera(cts, CYRPZ, &s->ct));
}
