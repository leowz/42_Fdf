/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_line_put.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 19:35:47 by zweng             #+#    #+#             */
/*   Updated: 2018/02/23 15:41:41 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	pf_init(t_vector *d, t_vector *s, t_vector start, t_vector end)
{
	d->x = ft_abs(end.x - start.x);
	d->y = -ft_abs(end.y - start.y);
	s->x = start.x < end.x ? 1 : -1;
	if (start.x == end.x)
		s->x = 0;
	s->y = start.y < end.y ? 1 : -1;
	if (start.y == end.y)
		s->y = 0;
	s->color = start.color < end.color ? 1 : -1;
	if (start.color == end.color)
		s->color = 0;
}

static void	adj_x(int *err, t_vector *start, t_vector d, t_vector s)
{
	*err += d.y;
	start->x += s.x;
}

static void	adj_y(int *err, t_vector *start, t_vector d, t_vector s)
{
	*err += d.x;
	start->y += s.y;
}

void		ft_mlx_image_line_put(t_vector start,
			t_vector end, t_image *img)
{
	t_vector	d;
	t_vector	s;
	int			err;
	int			e2;

	pf_init(&d, &s, start, end);
	err = (int)(d.x + d.y);
	while (1)
	{
		ft_img_pixel_put(img, (int)start.x, (int)start.y, end.color);
		if (ft_abs(start.x - end.x) < 1 && ft_abs(start.y - end.y) < 1)
			break ;
		e2 = 2 * err;
		if (e2 >= d.y)
			adj_x(&err, &start, d, s);
		if (e2 <= d.x)
			adj_y(&err, &start, d, s);
	}
}
