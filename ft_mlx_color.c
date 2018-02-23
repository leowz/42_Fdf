/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 18:58:17 by zweng             #+#    #+#             */
/*   Updated: 2018/02/23 15:40:29 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

int		ft_mlx_color(int red, int green, int blue)
{
	if (red > 255 || red < 0)
		return (0);
	if (green > 255 || green < 0)
		return (0);
	if (blue > 255 || blue < 0)
		return (0);
	return ((red << 16) + (green << 8) + blue);
}
