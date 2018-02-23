/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fx_hook_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 17:37:39 by zweng             #+#    #+#             */
/*   Updated: 2018/02/23 15:42:56 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx_keycode.h"

int		hook_mousedown(int button, int x, int y, t_mlx_data *mlx)
{
	if (x < 0 || y < 0 || x > WIN_W || y > WIN_H)
		return (0);
	if (button == BUT1_KEY || button == BUT2_KEY)
	{
		mlx->mouse.isdown = button;
	}
	if (button == SCROLLUP_KEY)
	{
		mlx->cam.scale += 2;
		if (mlx->cam.scale > (MAX_SCALE * mlx->cam.def_scale))
			mlx->cam.scale = (MAX_SCALE * mlx->cam.def_scale);
		fx_render(mlx);
	}
	if (button == SCROLLDOWN_KEY)
	{
		mlx->cam.scale -= 2;
		if (mlx->cam.scale < 2)
			mlx->cam.scale = 2;
		fx_render(mlx);
	}
	return (0);
}

int		hook_mouseup(int button, int x, int y, t_mlx_data *mlx)
{
	(void)button;
	if (x < 0 || y < 0 || x > WIN_W || y > WIN_H)
		return (0);
	mlx->mouse.isdown = 0;
	return (0);
}

int		hook_mousemove(int x, int y, t_mlx_data *mlx)
{
	if (x < 0 || y < 0 || x >= WIN_W || y >= WIN_H)
	{
		mlx->mouse.isdown = 0;
		return (0);
	}
	mlx->mouse.lastx = mlx->mouse.x;
	mlx->mouse.lasty = mlx->mouse.y;
	mlx->mouse.x = x;
	mlx->mouse.y = y;
	if (mlx->mouse.isdown == BUT1_KEY)
	{
		mlx->cam.x -= (mlx->mouse.lasty - y) / 200.0;
		mlx->cam.y += (mlx->mouse.lastx - x) / 200.0;
		fx_render(mlx);
	}
	else if (mlx->mouse.isdown == BUT2_KEY)
	{
		mlx->cam.offsetx -= (mlx->mouse.lastx - x);
		mlx->cam.offsety -= (mlx->mouse.lasty - y);
		fx_render(mlx);
	}
	return (0);
}
