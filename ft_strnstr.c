/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 11:21:52 by seocho            #+#    #+#             */
/*   Updated: 2020/10/26 12:12:25 by seocho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int i;
	int j;

	if (little[0] == '\0')
		return ((char*)big);

	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] && little[j] && len > i + j
				&& big[i + j] == little[j])
			j++;
		if (!little[j])
				return ((char*)(big + i));
		i++;
	}
	return (NULL);
}
	
