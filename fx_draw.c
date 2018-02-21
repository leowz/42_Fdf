/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fx_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:50:57 by zweng             #+#    #+#             */
/*   Updated: 2018/02/21 18:59:55 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_cam	pf_init_cam()
{
	t_cam	cam;

	cam.offsetx = WIN_W / 2;
	cam.offsety = WIN_H / 2;
	cam.x = 0.5;
	cam.y = 0.5;
	cam.z = -0.0;
	cam.scale = DEFAULT_SCALE;
	return (cam);
}

void	fx_draw(t_mlx_data *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_W, WIN_H, TITLE);
	mlx->image = ft_imgnew(mlx->mlx_ptr, WIN_W, WIN_H);
	mlx->cam = pf_init_cam();
	mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, 500, 500, COLOR_RED);
	fx_render(mlx);
//	mlx_key_hook(mlx->win_ptr, fx_keydown, mlx);
	mlx_hook(mlx->win_ptr, 4, 0, hook_mousedown, &(mlx->mouse));
	mlx_hook(mlx->win_ptr, 5, 0, hook_mouseup, &(mlx->mouse));
	mlx_hook(mlx->win_ptr, 6, 0, hook_mousemove, mlx);
	printf("before mlx_loop\n");
	mlx_loop(mlx->mlx_ptr);
}
