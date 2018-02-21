/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_line_put.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 19:35:47 by zweng             #+#    #+#             */
/*   Updated: 2018/02/21 18:59:48 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


static void	pf_init(t_vector *d, t_vector *s, t_vector start, t_vector end)
{
	d->x = ft_abs((int)(end.x - start.x));
	d->y = -ft_abs((int)(end.y - start.y));
	d->color = ft_abs(end.color - start.color);
	s->x = start.x < end.x ? 1 : -1;
	s->y = start.y < end.y ? 1 : -1;
	s->color = start.color < end.color ? 1 : -1;
}

static void adj_x(int *err, t_vector *start, t_vector d, t_vector s)
{
	*err += d.y;
	start->x += s.x;
	start->color += s.color;	
}

void		ft_mlx_image_line_put(t_vector start,
			t_vector end, t_image *img)
{
	t_vector	d;
	t_vector	s;
	int			err;
	int			e2;

	pf_init(&d, &s, start, end);
//	printf("start ");
//	p_vector(start);
//	printf("end ");
//	p_vector(end);
	err = (int)(d.x + d.y);
//	printf("err is %d\n", err);
	while (1)
	{
	//printf("start ");
//	p_vector(start);
//	printf("end ");
//	p_vector(end);
		ft_img_pixel_put(img, start.x, start.y, start.color); 
		if (ft_abs(start.x - end.x) < 1 && ft_abs(start.y - end.y) < 1)
			break ;
		e2 = 2 * err;
		if (e2 >= d.y)
			adj_x(&err, &start, d, s);
		if (e2 <= d.x)
		{
			err += d.x;
			start.y += s.y;
		}
	}
}
