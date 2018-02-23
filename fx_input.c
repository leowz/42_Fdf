/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fx_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 17:19:41 by zweng             #+#    #+#             */
/*   Updated: 2018/02/23 20:12:47 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	pf_del(char **line, char ***c_tab)
{
	int		i;

	i = 0;
	ft_strdel(line);
	while (c_tab && (*c_tab)[i])
	{
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
	if (!(size = fx_tablen((void **)c_tab)) || (map->width != 0 &&
		map->width < size) || !(row = ft_memalloc(sizeof(t_vector) * (size))))
		return (0);
	if (map->width == 0)
		map->width = size;
	while (i < map->width)
	{
		if (i < size)
			row[i] = fx_get_vector(index, i, c_tab[i]);
		else
			row[i] = fx_vector_zero(index, i);
		if (row[i].z < map->depth_min || (index == 0 && i == 0))
			map->depth_min = row[i].z;
		if (row[i].z > map->depth_max || (index == 0 && i == 0))
			map->depth_max = row[i].z;
		i++;
	}
	map->vectors[index] = row;
	return (1);
}

static int	pf_tab_convert(t_map *map, char **c_tab, int cur_height)
{
	if (map->height == 0)
	{
		map->height = INIT_SIZE_H;
		if (!(map->vectors = ft_memalloc(sizeof(t_vector *) * (map->height))))
			return (0);
	}
	if (cur_height >= map->height)
		fx_realloc_map(map);
	if (!pf_convert_line(map, c_tab, cur_height))
		return (0);
	return (cur_height + 1);
}

static char	**pf_line_convert(char *line)
{
	char	**ret;
	int		i;
	char	*ptr;

	i = 0;
	if (!(ret = ft_strsplit(line, ' ')))
		return (NULL);
	while (ret[i])
	{
		if (!fx_check_z(ret[i]))
			return (NULL);
		if ((ptr = ft_strchr(ret[i], ',')) && !fx_check_color(ret[i], ptr + 1))
			return (NULL);
		i++;
	}
	return (ret);
}

int			fx_get_input(t_map *map, int fd)
{
	char	*line;
	char	**c_tab;
	int		ret;
	int		cur_height;

	ret = 1;
	cur_height = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (!(c_tab = pf_line_convert(line)) ||
			!(cur_height = pf_tab_convert(map, c_tab, cur_height)))
		{
			ret = 0;
			break ;
		}
		else
			pf_del(&line, &c_tab);
	}
	map->height = cur_height;
	ft_strdel(&line);
	if (map->height <= 1 && map->width <= 1)
		return (0);
	return (ret);
}
