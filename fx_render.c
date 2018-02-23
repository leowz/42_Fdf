/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fx_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 21:11:11 by zweng             #+#    #+#             */
/*   Updated: 2018/02/23 14:40:57 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		pf_cal_color(t_vector v, t_map map)
{
	int max;
	int	min;
	int	dc;
	int	ret;

	max = map.depth_max;
	min = map.depth_min;
	if (max <= min)
		return (v.color);
	dc = (COLOR_WHITE - COLOR_BASE) / (max - min);
	ret = dc * (v.z - min) + COLOR_BASE;
	return (ret);
}

void	pf_render_line(t_vector v1, t_vector v2, t_mlx_data *mlx)
{
	t_vector	v1_f;
	t_vector	v2_f;

	v1_f = fx_transform(v1, mlx->cam, mlx->map);
	v2_f = fx_transform(v2, mlx->cam, mlx->map);
	if (mlx->cam.c_mode)
	{
		v1_f.color = pf_cal_color(v1, mlx->map);
		v2_f.color = pf_cal_color(v2, mlx->map);
	}
	ft_mlx_image_line_put(v1_f, v2_f, &(mlx->image));
}

void	pf_clear_image(t_image *img)
{
	ft_bzero(img->buf_ptr, (WIN_H * WIN_W * img->bpp));
}

void	fx_render(t_mlx_data *mlx)
{
	int			i;
	int			j;
	t_vector 	**v;

	i = 0;
	v = mlx->map.vectors;
	pf_clear_image(&(mlx->image));
	while (i < mlx->map.height)
	{
		j = 0;
		while (j < mlx->map.width)
		{
			if (j + 1 < mlx->map.width)
				pf_render_line(v[i][j], v[i][j + 1], mlx);
			if (i + 1 < mlx->map.height)
				pf_render_line(v[i][j], v[i + 1][j], mlx);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->image.img_ptr, 0, 0);
}
