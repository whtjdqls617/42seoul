/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 10:06:50 by seocho            #+#    #+#             */
/*   Updated: 2020/11/18 00:49:56 by seocho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	src;

	dst = b;
	src = c;
	i = 0;
	while (i < len)
	{
		*dst++ = src;
		i++;
	}
	return (b);
}
