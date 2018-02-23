/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fx_input_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 18:51:30 by zweng             #+#    #+#             */
/*   Updated: 2018/02/23 20:15:31 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	pf_ishex(const char c)
{
	return ((c <= 'F' && c >= 'A') || (c <= 'f' && c >= 'a'));
}

int			fx_check_z(char *line)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	if (!line)
		return (ret);
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && line[i] != ',' && line[i] != '+' &&
			line[i] != '-' && line[i] != ' ' && line[i] != '\t')
			return (0);
		if (ft_isdigit(line[i]))
			ret = 1;
		if (line[i] == ',' && i > 0)
			return (ret);
		i++;
	}
	return (ret);
}

int			fx_check_color(char *line, char *ptr)
{
	int		i;
	int		ret;

	i = ptr - line;
	ret = 0;
	if (!line || !ptr || (i >= (int)(ft_strlen(line))) || !line[i])
		return (ret);
	if (line[i] && line[i] == '0' && line[i + 1] && (line[i + 1] == 'x'
		|| line[i + 1] == 'X'))
		i += 2;
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && !pf_ishex(line[i]) && line[i] != ' ' &&
				line[i] != '\t' && line[i] != '+')
			return (0);
		ret = 1;
		i++;
	}
	return (ret);
}
