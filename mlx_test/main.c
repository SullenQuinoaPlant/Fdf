#include <stdio.h>
#include "mlx.h"

struct		mnw
{
	void	*mlx;
	void	*wdw;
};

void					key_reg(
	int k_code,
	void *ptrs)
{
	struct mnw *const	mnw = (struct mnw*)ptrs;
	char				buffer[1000];

	snprintf(buffer, 1000, "%d", k_code);
	mlx_clear_window(mnw->mlx, mnw->wdw);
	mlx_string_put(mnw->mlx, mnw->wdw, 0, 0, 0xffffff, buffer);
}

int						main()
{
	struct mnw	mnw;

	mnw.mlx = mlx_init();
	mnw.wdw = mlx_new_window(mnw.mlx, 1000, 1000, "a window");
	mlx_key_hook(mnw.wdw, (int(*)())key_reg, &mnw);
	mlx_loop(mnw.mlx);
}
