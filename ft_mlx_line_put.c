/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_line_put.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 19:35:47 by zweng             #+#    #+#             */
/*   Updated: 2018/02/25 15:13:26 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static void	pf_init(t_point *d, t_point *s, t_point start, t_point end)
{
	d->x = ft_abs(end.x - start.x);
	d->y = -ft_abs(end.y - start.y);
	s->x = start.x < end.x ? 1 : -1;
	if (start.x == end.x)
		s->x = 0;
	s->y = start.y < end.y ? 1 : -1;
	if (start.y == end.y)
		s->y = 0;
}

static void	adj_x(int *err, t_point *start, t_point d, t_point s)
{
	*err += d.y;
	start->x += s.x;
}

static void	adj_y(int *err, t_point *start, t_point d, t_point s)
{
	*err += d.x;
	start->y += s.y;
}

static void	bres(t_point start, t_point end, int color, t_image *img)
{
	t_point		d;
	t_point		s;
	int			err;
	int			e2;

	pf_init(&d, &s, start, end);
	err = d.x + d.y;
	while (1)
	{
		ft_img_pixel_put(img, start.x, start.y, color);
		if (start.x == end.x && start.y == end.y)
			break ;
		e2 = 2 * err;
		if (e2 >= d.y)
			adj_x(&err, &start, d, s);
		if (e2 <= d.x)
			adj_y(&err, &start, d, s);
	}
}

void		ft_mlx_image_line_put(t_vector start,
			t_vector end, t_image *img)
{
	t_point p1;
	t_point p2;

	p1.x = round(start.x);
	p1.y = round(start.y);
	p2.x = round(end.x);
	p2.y = round(end.y);
	bres(p1, p2, end.color, img);
}
