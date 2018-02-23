/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fx_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:50:57 by zweng             #+#    #+#             */
/*   Updated: 2018/02/23 15:18:41 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_cam	fx_init_cam(t_map map)
{
	t_cam	cam;
	int		s1;
	int		s2;

	cam.offsetx = WIN_W / 2;
	cam.offsety = WIN_H / 2;
	cam.x = 0.5;
	cam.y = 0.5;
	cam.z = 0.0;
	s1 = (WIN_W) / (map.width * 2);
	s2 = (WIN_H) / (map.height * 2);
	cam.scale = s1 < s2 ? s1 : s2;
	if (cam.scale < 1)
		cam.scale = 1;
	cam.def_scale = cam.scale;
	cam.c_mode = 0;
	return (cam);
}

void	fx_draw(t_mlx_data *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_W, WIN_H, TITLE);
	mlx->image = ft_imgnew(mlx->mlx_ptr, WIN_W, WIN_H);
	mlx->cam = fx_init_cam(mlx->map);
	fx_render(mlx);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 10, COLOR_WHITE, USAGE_STRING);
	mlx_key_hook(mlx->win_ptr, hook_key, mlx);
	mlx_hook(mlx->win_ptr, 4, 0, hook_mousedown, mlx);
	mlx_hook(mlx->win_ptr, 5, 0, hook_mouseup, mlx);
	mlx_hook(mlx->win_ptr, 6, 0, hook_mousemove, mlx);
	mlx_loop(mlx->mlx_ptr);
}
