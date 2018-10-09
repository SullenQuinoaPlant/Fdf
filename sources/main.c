#include "functions.h"
#include "auxilliaries.h"

int				main(
	int ac,
	char **av)
{
	t_s_sbi	*input[2];
	t_s_s	*scene;

	if (ac == 1)
		return (0);
	get_cdgfxyrz_sbi(av[1], input);
	input[2] = 0;
	make_scene(input[0], &scene);
	print_scene_points(scene);
	scene_teardown(&scene);	
	return (0);
}
