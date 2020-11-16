/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 10:10:55 by seocho            #+#    #+#             */
/*   Updated: 2020/11/16 10:30:13 by seocho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	find_set(char c, char const *set)
{
	size_t i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	size_t	i;
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1);
	while (start < end && find_set(s1[start], set))
		start++;
	while (end > start && find_set(s1[end - 1], set))
		end--;
	new = (char*)malloc(sizeof(char) * (end - start + 1));
	i = 0;
	while (start < end)
	{
		new[i] = s1[start];
		i++;
		start++;
	}
	new[i] = '\0';
	return (new);
}
