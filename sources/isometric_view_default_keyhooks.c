#include "functions.h"
#include "scene.h"
#include "key_codes.h"
#include "mlx.h"

void							isometric_keyhooks(
	int keycode,
	void *view)
{
	t_s_sv *const	v = (t_s_sv*)view;
	t_s_s			*s;

	if (!(s = v->s))
		return ;
	if (keycode == K_ESC)
	{
		scene_teardown(&s);
		exit(0);
	}
}
