/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 10:06:11 by seocho            #+#    #+#             */
/*   Updated: 2020/11/16 10:17:23 by seocho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char*)(ptr1 + i) != *(unsigned char*)(ptr2 + i))
			return (*(unsigned char*)(ptr1 + i) - *(unsigned char*)(ptr2 + i));
		i++;
	}
	return (0);
}
