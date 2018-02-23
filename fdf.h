/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 14:11:11 by zweng             #+#    #+#             */
/*   Updated: 2018/02/23 19:15:33 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include "ft_mlx.h"
# include "libft.h"

# define INIT_SIZE_H	(5)
# define TITLE			("FDF TITLE")
# define RATIO			(4 / 5)
# define MAX_SCALE		(5)
# define USAGE_STRING	("Usage: esc exit, r reset, c color mode.")

typedef struct	s_cam
{
	double		offsetx;
	double		offsety;
	double		x;
	double		y;
	double		z;
	int			scale;
	int			c_mode;
	int			def_scale;
}				t_cam;

typedef struct	s_map
{
	int			width;
	int			height;
	int			depth_min;
	int			depth_max;
	t_vector	**vectors;
}				t_map;

typedef struct	s_mouse
{
	char		isdown;
	int			x;
	int			y;
	int			lastx;
	int			lasty;
}				t_mouse;

typedef struct	s_mlx_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_image		image;
	t_map		map;
	t_cam		cam;
	t_mouse		mouse;
}				t_mlx_data;

int				fx_get_input(t_map *map, int fd);
int				fx_tablen(void **tab);
int				fx_check_z(char *line);
int				fx_check_color(char	*line, char *ptr);
int				fx_realloc_map(t_map *map);
t_vector		fx_get_vector(int i, int j, char *str);
t_vector		fx_vector_zero();
int				ft_atoi_hex(const char *str);
void			fx_draw(t_mlx_data *mlx);
void			fx_render(t_mlx_data *mlx);
void			ft_mlx_image_line_put(t_vector start,
				t_vector end, t_image *img);
t_vector		fx_transform(t_vector v, t_cam cam, t_map map);
t_cam			fx_init_cam(t_map map);
int				hook_mousemove(int x, int y, t_mlx_data *mlx);
int				hook_mousedown(int button, int x, int y, t_mlx_data *mlx);
int				hook_mouseup(int button, int x, int y, t_mlx_data *mlx);
int				hook_key(int key, t_mlx_data *mlx);
void			ft_put_image_line(t_vector start, t_vector end, t_image *img);
#endif
