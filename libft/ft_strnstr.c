/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 12:05:24 by thaley            #+#    #+#             */
/*   Updated: 2018/12/11 12:05:25 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*needle == '\0')
		return ((char *)(haystack + i));
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0] && i < len)
		{
			j = 0;
			while (haystack[i + j] == needle[j] && i + j < len)
			{
				j++;
				if (needle[j] == '\0')
					return ((char *)(haystack + i));
			}
		}
		i++;
	}
	return (NULL);
}
