/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fx_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 17:19:41 by zweng             #+#    #+#             */
/*   Updated: 2018/02/21 18:59:48 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pf_del(char **line, char ***c_tab)
{
	int		i;

	i = 0;
	ft_strdel(line);
//	ft_putstr("del line\n");
	while (c_tab && (*c_tab)[i])
	{
		//printf("del tab row %d\n", i);
		ft_strdel(&((*c_tab)[i]));
		i++;
	}
	ft_memdel((void **)c_tab);
}

static int	pf_convert_line(t_map *map, char **c_tab, int index)
{
	int			size;
	int			i;
	t_vector	*row;

	i = 0;
	//printf("enter convert line at row %d\n", index);
	if (!(size = fx_tablen((void **)c_tab)) || (map->width != 0 &&
		map->width != size))
		return (0);
	if (map->width == 0)
		map->width = size;
	//printf("size get is %d\n", size);
	if (!(row = ft_memalloc(sizeof(t_vector) * (size))))
	{
		return (0);
	}
	while (i < size)
	{
//	printf("before get vector\n");
		row[i] = fx_get_vector(index, i, c_tab[i]);
		if (row[i].z < map->depth_min)
			map->depth_min = row[i].z;
		if (row[i].z > map->depth_max)
			map->depth_max = row[i].z;
//	printf("after get vector\n");
		i++;
	}
	map->vectors[index] = row;
	return (1);
}

static int	pf_tab_convert(t_map *map, char **c_tab, int cur_height)
{
	printf("enter tab convert\n");
	if (map->height == 0)
	{
		map->height = INIT_SIZE_H;
		if (!(map->vectors = ft_memalloc(sizeof(t_vector *) * (map->height))))
		{
			return (0);
		}
	}
	if (cur_height >= map->height)
	{
		printf("map height not enough, realloc\n");
		fx_realloc_map(map);
	}
	if (!pf_convert_line(map, c_tab, cur_height))
		return (0);
	return (cur_height + 1);
}

/*static int	pf_checkline(const char *line)
{
	if (!line)
		return (0);
	while (*line)
	{
		if (!ft_isdigit(*line) && *line != ' ' && *line != '+' && *line != '-')
		{
			return (0);
		}
		line++;
	}
	return (1);
}*/

int			fx_get_input(t_map *map, int fd)
{
	char	*line;
	char	**c_tab;
	int		ret;
	int		cur_height;

	ret = 1;
	cur_height = 0;
//	printf("before GNL\n");
	while (get_next_line(fd, &line) > 0)
	{
//	printf("----------start one line-----------\n");
//	printf("get line %s\n", line);
		if (!(c_tab = ft_strsplit(line, ' ')) ||
			!(cur_height = pf_tab_convert(map, c_tab, cur_height)))
		{
			ret = 0;
		//	printf("----------finish GNL-----------\n");
			break ;
		}
		else
		{
			pf_del(&line, &c_tab);
	//		printf("----------finish one line-----------\n");
		}
	}
	//printf("after GNL\n");
	map->height = cur_height;
	ft_strdel(&line);
	return (ret);
}
