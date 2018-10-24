#include "mlx.h"
#include "functions.h"
#include "scene.h"

static void				free_pxl_ars(
	t_s_sv *v)
{
	size_t const	sz = v->h * v->w * sizeof(double);

	if (v->pxl_prec)
	{
		free(v->pxl_prec);
		v->s->pxl_allocs += sz;
	}
}

static void				release_mlx_ptrs(
	t_s_sv *v)
{
	void *const	mlx = v->s->mlx;

	if (v->mlx_img)
		mlx_destroy_image(mlx, v->mlx_img);
	if (v->mlx_wdw)
		mlx_destroy_window(mlx, v->mlx_wdw);
}

static void				free_tars(
	t_s_sv *v)
{
	t_e_seg			i;

	i = -1;
	while (++i < e_seg_sz)
		free_tar(v->e[i].ar, v->e[i].ar_sz, v->e[i].e_sz, v->s);
}

void					free_view_members(
	t_s_sv *v)
{
	if (!v)
		return ;
	tspctr_onelessview(v->ct);
	free_pxl_ars(v);
	free_tars(v);
	release_mlx_ptrs(v);
}
