/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 21:34:07 by zweng             #+#    #+#             */
/*   Updated: 2018/02/23 13:57:23 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

void	ft_img_pixel_put(t_image *img, int x, int y, int color)
{
	if (x <= 0 || x >= WIN_W || y <= 0 || y >= WIN_H)
		return ;
	*((int *)(img->buf_ptr + ((x + y * WIN_W) * img->bpp))) = color;
}
