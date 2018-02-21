/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fx_hook_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 17:37:39 by zweng             #+#    #+#             */
/*   Updated: 2018/02/21 18:59:45 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx_keycode.h"

int		hook_mousedown(int button, int x, int y, t_mouse *mouse)
{
	if (x < 0 || y < 0)
		return (0);
	printf("mousedown button == %d\n", button);
	if (button == BUT1_KEY)
	{
		printf("press key 1\n");
		mouse->isdown = 1;
	}
	return (0);
}

int		hook_mouseup(int button, int x, int y, t_mouse *mouse)
{
	if (x < 0 || y < 0)
		return (0);
	printf("mouseup button == %d\n", button);
//	if (button != BUT1_KEY)
//	{
		printf("let go key 1\n");
		mouse->isdown = 0;
//	}
	return (0);
}

int		hook_mousemove(int x, int y, t_mlx_data *mlx)
{
	if (x < 0 || y < 0)
		return (0);
	mlx->mouse.lastx = mlx->mouse.x;
	mlx->mouse.lasty = mlx->mouse.y;
	mlx->mouse.x = x;
	mlx->mouse.y = y;
	if (mlx->mouse.isdown)
	{
		printf("press key 1\n");
		mlx->mouse.isdown = 1;
		mlx->cam.x -= (mlx->mouse.lasty - y) / 200.0;
		mlx->cam.y += (mlx->mouse.lastx - x) / 200.0;
		fx_render(mlx);
	}
	else
	{
		printf("let go key 1\n");
		mlx->mouse.isdown = 0;
	}
	return (0);	
}
