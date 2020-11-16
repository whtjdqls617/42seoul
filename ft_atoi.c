/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 12:12:38 by seocho            #+#    #+#             */
/*   Updated: 2020/11/14 15:56:48 by seocho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int			is_operator(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

int			is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	long	result;
	long	minus;
	size_t	i;

	i = 0;
	minus = 1;
	while (str[i] && is_space(str[i]) == 1)
		i++;
	if (str[i] == '-')
		minus *= -1;
	if (is_operator(str[i]))
		i++;
	result = 0;
	while (is_number(str[i]))
	{
		result *= 10;
		result += (str[i] - '0');
		if (result > 2147483647 && minus == 1)
			return (-1);
		if (result > 2147483648 && minus == -1)
			return (0);
		i++;
	}
	return (result * minus);
}
