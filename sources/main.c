#include "functions.h"
#include "auxilliaries.h"

int				main(
	int ac,
	char **av)
{
	t_s_sbi	*input[2];
	t_s_s	*scene;
	t_s_sv	*view;

	if (ac == 1)
		return (0);
	input[2] = 0;
	if (get_cdgfxyrz_sbi(av[1], input) == SUCCESS &&
		make_scene(input, &scene) == SUCCESS &&
		add_isometric_v(scene, 110, 510) == SUCCESS)
	{
		print_scene_points(scene);
		print_view(view);
	}
	scene_teardown(&scene);	
	return (0);
}
