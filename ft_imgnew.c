/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imgnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 21:22:03 by zweng             #+#    #+#             */
/*   Updated: 2018/02/20 23:57:46 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"
#include "libft.h"

t_image		ft_imgnew(void *mlx_ptr, int width, int height)
{
	t_image	image;

	ft_bzero(&image, sizeof(t_image));
	image.img_ptr = mlx_new_image(mlx_ptr, width, height);
	if (image.img_ptr == NULL)
		return (image);
	image.buf_ptr = mlx_get_data_addr(image.img_ptr, &image.bpp,
					&image.size_line, &image.endian);
	image.bpp /= 8;
	return (image);
}
