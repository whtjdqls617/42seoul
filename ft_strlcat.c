/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seocho </var/mail/seocho>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 16:44:11 by seocho            #+#    #+#             */
/*   Updated: 2020/10/22 14:14:16 by seocho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlcat(char *dst, char *src, size_t size)
{
	int i;
	int	dst_len;
	int	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;

	if(dst_len + 1 > size)
	{
		while(src[i] && dst_len + i < size - 1)
		{
			dst[dst_len] = src[i];
			dst_len += 1;
			i++;
		}
		dst[dst_len] = '\0';
	}
	if(dst_len > size - 1)
		dst_len = size;
				
