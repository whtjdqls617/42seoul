/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 10:10:05 by seocho            #+#    #+#             */
/*   Updated: 2020/11/16 10:27:54 by seocho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static void		ft_strrev(char *str)
{
	size_t		len;
	size_t		i;
	char		temp;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
		i++;
	}
}

char			*ft_itoa(int n)
{
	char		*str;
	int			minus;
	int			i;

	minus = (n < 0);
	if (!(str = ft_calloc(11 + minus, sizeof(*str))))
		return (0);
	if (n == 0)
		str[0] = '0';
	i = 0;
	while (n != 0)
	{
		str[i] = ft_abs(n % 10) + '0';
		n = n / 10;
		i++;
	}
	if (minus == 1)
		str[i] = '-';
	ft_strrev(str);
	return (str);
}
