/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 12:56:02 by thaley            #+#    #+#             */
/*   Updated: 2018/12/04 12:56:03 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*add_haystack;
	const char	*add_needle;

	if ((*haystack == '\0' && *needle == '\0') || *needle == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			add_haystack = haystack;
			add_needle = needle;
			while (*add_haystack == *add_needle)
			{
				if (*add_needle == '\0' || *add_haystack == '\0')
					return ((char *)haystack);
				add_haystack++;
				add_needle++;
			}
			if (*add_needle == '\0')
				return ((char *)haystack);
		}
		haystack++;
	}
	return (0);
}
