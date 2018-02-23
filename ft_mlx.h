/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 19:23:04 by zweng             #+#    #+#             */
/*   Updated: 2018/02/23 15:18:34 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_MLX_H
# define FT_MLX_H

# include "mlx.h"

# define WIN_H			(1300)
# define WIN_W			(1800)
# define COLOR_BLACK	(0x000000)
# define COLOR_RED		(0xFF0000)
# define COLOR_WHITE	(0xFFFFFF)
# define COLOR_GREEN	(0x00FF00)
# define COLOR_BLUE		(0x0000FF)
# define COLOR_YELLOW	(0xFFFF00)
# define COLOR_CYAN		(0x00FFFF)
# define COLOR_SILVER	(0xC0C0C0)
# define COLOR_PURPLE	(0x800080)
# define COLOR_BASE		COLOR_GREEN

typedef	struct	s_mlx_context
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_mlx_context;

typedef	struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef	struct	s_frame
{
	t_point		origin;
	t_point		center;
	int			height;
	int			width;
}				t_frame;

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
	int			color;
}				t_vector;

/*
 *	img_ptr		: the image pointer created by mlx_new_image
 *	buf_ptr		: the address represents the begining of the memory area for image
 *	size_line	: number of bytes used to store one line of image in memory
 *	bpp			: bytes per pixel, number of bytes needed to represent a pixel color
 *	endian		: little endian(endian == 0); big endian(endian == 1) 
 */
typedef struct	s_image
{
	void		*img_ptr;
	char		*buf_ptr;
	int			bpp;
	int			size_line;
	int			endian;
}				t_image;

int				ft_mlx_color(int red, int green, int blue);
void			ft_img_pixel_put(t_image *img, int x, int y, int color);
t_image			ft_imgnew(void *mlx_ptr, int width, int height);
#endif
