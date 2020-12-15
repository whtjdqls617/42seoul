/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 12:12:38 by seocho            #+#    #+#             */
/*   Updated: 2020/11/24 16:04:50 by seocho           ###   ########.fr       */
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
	unsigned long long	result;
	int					minus;
	int					i;

	i = 0;
	minus = 1;
	while (str[i] && is_space(str[i]))
		i++;
	if (str[i] == '-')
		minus *= -1;
	if (is_operator(str[i]))
		i++;
	result = 0;
	while (is_number(str[i]))
	{
		result = (10 * result) + (str[i] - '0');
		i++;
	}
	if (result > 9223372036854775807 && minus == 1)
		return (-1);
	if (result >= 9223372036854775807 && minus == -1)
		return (0);
	return (result * minus);
}
