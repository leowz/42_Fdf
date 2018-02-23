/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fx_hook_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:16:34 by zweng             #+#    #+#             */
/*   Updated: 2018/02/23 15:42:26 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx_keycode.h"

int		hook_key(int key, t_mlx_data *mlx)
{
	if (key == ESC_KEY)
		exit(0);
	if (key == R_KEY)
	{
		mlx->cam = fx_init_cam(mlx->map);
	}
	if (key == C_KEY)
	{
		if (mlx->cam.c_mode)
			mlx->cam.c_mode = 0;
		else
			mlx->cam.c_mode = 1;
	}
	fx_render(mlx);
	return (0);
}
