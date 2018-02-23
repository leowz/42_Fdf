/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 14:12:24 by zweng             #+#    #+#             */
/*   Updated: 2018/02/23 14:03:41 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pf_prep_end(t_map *map, int fd)
{
	int		i;

	i = 0;
	while (i < map->height && map->vectors[i])
	{
		ft_memdel((void **)&(map->vectors[i]));
		i++;
	}
	ft_memdel((void **)&(map->vectors));
	if (fd > 2)
		close(fd);
}

int		pf_get_fd(int ac, char **av)
{
	if (ac > 2)
		return (-1);
	else if (ac == 1)
		return (STDIN_FILENO);
	else if (ac == 2)
		return (open(av[1], O_RDONLY));
	return (-1);
}

int		main(int ac, char **av)
{
	int			fd;
	t_map		map;
	t_mlx_data	mlx;

	if ((fd = pf_get_fd(ac, av)) < 0)
	{
		ft_putstr("FD ERROR!\n");
		return (1);
	}
	ft_bzero(&map, sizeof(t_map));
	ft_bzero(&mlx, sizeof(t_mlx_data));
	if (fx_get_input(&map, fd))
	{
		mlx.map = map;
		fx_draw(&mlx);
	}
	else
		ft_putstr("INPUT ERROR!\n");
		return (1);
	pf_prep_end(&map, fd);
	return (0);
}
