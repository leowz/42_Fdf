/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 18:00:32 by zweng             #+#    #+#             */
/*   Updated: 2018/02/20 18:31:37 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		get_digit(const char c)
{
	const char	*s1;
	const char	*s2;
	int			i;

	s1 = "0123456789ABCDEF";
	s2 = "0123456789abcdef";
	i = 0;
	while (i < 16 && s1[i] != c && s2[i] != c)
		i++;
	if (i == 16)
		return (-1);
	return (i);
}

int		ft_atoi_hex(const char *str)
{
	int		ret;
	int		digit;
	int		i;

	ret = 0;
	i = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v' || *str
	== '\f' || *str == '\r')
		str++;
	if (*str == '0' && (*(str + 1) == 'x' || *(str + 1) == 'X'))
		str += 2;
	while (1 && i < 20 && *str)
	{
		digit = get_digit(*str++);
		if (digit > 15 || digit < 0)
			break ;
		ret = (16 * ret) + digit;
		i++;
	}
	return (i < 20 ? ret : -1);
}
