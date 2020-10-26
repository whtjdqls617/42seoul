/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 10:27:21 by seocho            #+#    #+#             */
/*   Updated: 2020/10/26 11:20:29 by seocho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *str1, const char *str2, size_t count)
{
	int i;

	i = 0;
	while (i < count && (str1[i] || str2[i]))
	{
		if (str1[i] > str2[i])
			return (1);
		else if (str1[i] < str2[i])
			return (-1);
		i++;
	}
	
	if (count == i)
		return (0);
	else if (str1[i] == '\0' && str2[i] == '\0')
		return (0);
	else if (str1[i] > str2[i])
		return 1;
	else
		return -1;
}
