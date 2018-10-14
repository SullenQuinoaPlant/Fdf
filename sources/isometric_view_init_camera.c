#define SIN_PI_4 0xb.504f333f9de6485p-4
#define COS_PI_4 0xb.504f333f9de6484p-4
#define SQRT_2 0xb.504f333f9de6484p-3
#define SQRT_3 0xd.db3d742c265539ep-3

t_s_pctr					*add_isometric_camera(
	double zoom,
	double tr[DIMS],
	t_s_s *s)
{
	t_pctrm const	cts[4] = {
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
		{{zoom, 0, 0},
		{0, zoom, 0},
		{0, 0, zoom},
		{tr[X], tr[Y], tr[Z]}}};

	return (add_camera(cts, 4, s));
}
