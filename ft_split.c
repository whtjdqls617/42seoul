/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 10:10:20 by seocho            #+#    #+#             */
/*   Updated: 2020/11/16 12:45:05 by seocho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_array(char const *s, char c)
{
	int			count;
	int			i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue;
		}
		count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char		**memory_free(char **s)
{
	int i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

char			**ft_split(const char *s, char c)
{
	char	**new;
	size_t	i;
	size_t	sub_count;

	i = 0;
	sub_count = count_array(s, c);
	new = (char **)malloc(sizeof(char*) * (sub_count + 1));
	while (i < sub_count)
	{
		while (*s && *s == c)
			s++;
		if (!(new[i] = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
			return (memory_free(new));
		ft_strlcpy(new[i], s, (ft_strlen(s) + 1));
		i++;
		if (i < sub_count)
			s += ft_strlen(s);
	}
	new[i] = 0;
	return (new);
}
