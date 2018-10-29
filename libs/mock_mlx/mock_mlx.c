/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmauvari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:17:34 by nmauvari          #+#    #+#             */
/*   Updated: 2018/10/29 20:37:20 by nmauvari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

void							*mlx_init(
	void)
{
	return ((void*)1);
}

void							*mlx_new_window(
	void *mlx_ptr,
	int size_x,
	int size_y,
	char *title)
{
	(void)mlx_ptr;
	(void)size_x;
	(void)size_y;
	(void)title;
	return ((void*)1);
}

int								mlx_clear_window(
	void *mlx_ptr,
	void *win_ptr)
{
	(void)mlx_ptr;
	(void)win_ptr;
	return (0);
}

int								mlx_pixel_put(
	void *mlx_ptr,
	void *win_ptr,
	int x,
	int y,
	int color)
{
	(void)mlx_ptr;
	(void)win_ptr;
	(void)x;
	(void)y;
	(void)color;
	return (0);
}

void							*mlx_new_image(
	void *mlx_ptr,
	int width,
	int height)
{
	(void)mlx_ptr;
	(void)width;
	(void)height;
	return ((void*)1);
}

#define DUMM_IMG_AR 1000000

char							g_big_fat_ugly_ar[DUMM_IMG_AR];

char							*mlx_get_data_addr(
	void *img_ptr,
	int *bits_per_pixel,
	int *size_line,
	int *endian)
{
	(void)img_ptr;
	*bits_per_pixel = 32;
	*size_line = 400;
	*endian = 0;
	return (g_big_fat_ugly_ar);
}

int								mlx_put_image_to_window(
	void *mlx_ptr,
	void *win_ptr,
	void *img_ptr,
	int x,
	int y)
{
	(void)mlx_ptr;
	(void)win_ptr;
	(void)img_ptr;
	(void)x;
	(void)y;
	return (0);
}

unsigned int					mlx_get_color_value(
	void *mlx_ptr,
	int color)
{
	(void)mlx_ptr;
	(void)color;
	return (0);
}

int								mlx_mouse_hook(
	void *win_ptr,
	int (*funct_ptr)(),
	void *param)
{
	(void)win_ptr;
	(void)funct_ptr;
	(void)param;
	return (0);
}

int								mlx_key_hook(
	void *win_ptr,
	int (*funct_ptr)(),
	void *param)
{
	(void)win_ptr;
	(void)funct_ptr;
	(void)param;
	return (0);
}

int								mlx_expose_hook(
	void *win_ptr,
	int (*funct_ptr)(),
	void *param)
{
	(void)win_ptr;
	(void)funct_ptr;
	(void)param;
	return (0);
}

int								mlx_loop_hook(
	void *mlx_ptr,
	int (*funct_ptr)(),
	void *param)
{
	(void)mlx_ptr;
	(void)funct_ptr;
	(void)param;
	return (0);
}

int								mlx_loop(
	void *mlx_ptr)
{
	(void)mlx_ptr;
	return (0);
}

int								mlx_string_put(
	void *mlx_ptr,
	void *win_ptr,
	int x,
	int y,
	int color,
	char *string)
{
	(void)mlx_ptr;
	(void)win_ptr;
	(void)x;
	(void)y;
	(void)color;
	(void)string;
	return (0);
}

void							*mlx_xpm_to_image(
	void *mlx_ptr,
	char **xpm_data,
	int *width,
	int *height)
{
	(void)mlx_ptr;
	(void)xpm_data;
	(void)width;
	(void)height;
	return (0);
}

void							*mlx_xpm_file_to_image(
	void *mlx_ptr,
	char *filename,
	int *width,
	int *height)
{
	(void)mlx_ptr;
	(void)filename;
	(void)width;
	(void)height;
	return (0);
}

int								mlx_destroy_window(
	void *mlx_ptr,
	void *win_ptr)
{
	(void)mlx_ptr;
	(void)win_ptr;
	return (0);
}

int								mlx_destroy_image(
	void *mlx_ptr,
	void *img_ptr)
{
	(void)mlx_ptr;
	(void)img_ptr;
	return (0);
}

int								mlx_hook(
	void *win_ptr,
	int x_event,
	int x_mask,
	int (*funct)(),
	void *param)
{
	(void)win_ptr;
	(void)x_event;
	(void)x_mask;
	(void)funct;
	(void)param;
	return (0);
}

int								mlx_do_key_autorepeatoff(
	void *mlx_ptr)
{
	(void)mlx_ptr;
	return (0);
}

int								mlx_do_key_autorepeaton(
	void *mlx_ptr)
{
	(void)mlx_ptr;
	return (0);
}

int								mlx_do_sync(
	void *mlx_ptr)
{
	(void)mlx_ptr;
	return (0);
}
