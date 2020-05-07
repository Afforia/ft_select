/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 14:57:34 by thaley            #+#    #+#             */
/*   Updated: 2018/12/19 14:57:35 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cps;
	int				i;

	cps = (unsigned char *)s;
	i = 0;
	while (n > 0)
	{
		if (cps[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
		n--;
	}
	return (NULL);
}
