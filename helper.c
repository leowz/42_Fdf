/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 20:17:35 by zweng             #+#    #+#             */
/*   Updated: 2018/02/21 18:59:51 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	p_vector(t_vector v)
{
	printf("(%.2f, %.2f, %.2f, %#x)\n", v.x, v.y, v.z, v.color);
}

void	print_line(t_vector*  v_ptr, int size)
{
	int		i = 0;

	while (i < size)
	{
	printf("(%.0f,%.0f,%.0f,%d) ", v_ptr[i].x, v_ptr[i].y, v_ptr[i].z, v_ptr[i].color);
	//	printf("(%.0f,%.0f,%.0f) ", v_ptr[i].x, v_ptr[i].y, v_ptr[i].z);
		i++;
	}
	printf("\n");
}

void 	print_map(t_map *map)
{
	int		i = 0;

	printf("#------------tab %d * %d--------------#i\n", map->height, map->width);
	while (i < map->height)
	{
		print_line(map->vectors[i], map->width);
		i++;
	}
	printf("#------------tab %d * %d--------------#i\n", map->height, map->width);
}
