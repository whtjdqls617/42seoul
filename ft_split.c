/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 10:10:20 by seocho            #+#    #+#             */
/*   Updated: 2020/11/17 15:32:24 by seocho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		count_array(char const *s, char c)
{
	size_t			count;
	size_t			i;

	count = 0;
	i = 0;
	if (!*s)
		return (0);
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			count++;
			while (s[i] && s[i] == c)
				i++;
		}
		else
			i++;
	}
	if (s[i - 1] != c)
		count++;
	return (count);
}

static char			**memory_free(char **s)
{
	int				i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static size_t		get_len(const char *s, char c)
{
	size_t			i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			break ;
		i++;
	}
	return (i);
}

char				**ft_split(const char *s, char c)
{
	char			**new;
	size_t			i;
	size_t			sub_count;
	size_t			len;

	if (!s)
		return (0);
	sub_count = count_array(s, c);
	if (!(new = (char **)malloc(sizeof(char*) * (sub_count + 1))))
		return (0);
	i = 0;
	while (i < sub_count)
	{
		while (*s && *s == c)
			s++;
		len = get_len(s, c);
		if (!(new[i] = (char *)malloc(sizeof(char) * len + 1)))
			return (memory_free(new));
		ft_strlcpy(new[i], s, len + 1);
		i++;
		if (i < sub_count)
			s += len;
	}
	new[i] = 0;
	return (new);
}
