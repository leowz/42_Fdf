/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fx_input_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 19:16:05 by zweng             #+#    #+#             */
/*   Updated: 2018/02/23 20:13:21 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			fx_tablen(void **tab)
{
	int		i;

	i = 0;
	while ((char *)tab != NULL && (char *)(tab[i]) != NULL)
		i++;
	return (i);
}

int			fx_realloc_map(t_map *map)
{
	t_vector	**vec;
	int			i;

	i = 0;
	if (!(vec = ft_memalloc(sizeof(t_vector *) * map->height * 2)))
		return (0);
	while (i < map->height)
	{
		vec[i] = map->vectors[i];
		i++;
	}
	ft_memdel((void **)&map->vectors);
	map->vectors = vec;
	map->height = map->height * 2;
	return (1);
}

int			pf_atoi(const char *str)
{
	if (!str || !(*str))
		return (COLOR_BASE);
	if (ft_strstr(str, "0X") || ft_strstr(str, "0x"))
		return (ft_atoi_hex(str));
	else
		return (ft_atoi(str));
}

t_vector	fx_get_vector(int i, int j, char *str)
{
	t_vector	ret;

	ret.x = (double)j;
	ret.y = (double)i;
	ret.z = (double)ft_atoi(str);
	if (str && ft_strchr(str, ','))
		ret.color = pf_atoi(ft_strchr(str, ',') + 1);
	else
		ret.color = COLOR_BASE;
	return (ret);
}

t_vector	fx_vector_zero(int i, int j)
{
	t_vector	ret;

	ft_bzero(&ret, sizeof(t_vector));
	ret.x = (double)j;
	ret.y = (double)i;
	ret.z = 0;
	ret.color = COLOR_WHITE;
	return (ret);
}
