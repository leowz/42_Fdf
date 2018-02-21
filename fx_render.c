/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fx_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 21:11:11 by zweng             #+#    #+#             */
/*   Updated: 2018/02/21 18:59:56 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pf_render_line(t_vector v1, t_vector v2, t_mlx_data *mlx)
{
	t_vector	v1_f;
	t_vector	v2_f;

//	printf("enterr ender line\n");
//	p_vector(v1);
	v1_f = fx_transform(v1, mlx->cam, mlx->map);
//	p_vector(v1_f);
//	printf("before transform v2\n");
//	p_vector(v2);
	v2_f = fx_transform(v2, mlx->cam, mlx->map);
//	p_vector(v2_f);
//	printf("before mlx_img_linput\n");
	printf("v1 ");
	p_vector(v1_f);
	printf("v2 ");
	p_vector(v2_f);
	ft_mlx_image_line_put(v1_f, v2_f, &(mlx->image));
//	printf("after mlx_img_linput\n");
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
	printf("map height is %d, width is %d\n", mlx->map.height, mlx->map.width);
	while (i < mlx->map.height)
	{
		j = 0;
		while (j < mlx->map.width)
		{
			if (j + 1 < mlx->map.width)
			{
				pf_render_line(v[i][j], v[i][j + 1], mlx);
			}
			if (i + 1 < mlx->map.height)
			{
				pf_render_line(v[i][j], v[i + 1][j], mlx);
			}
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->image.img_ptr, 0, 0);
}
