/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 16:05:18 by thaley            #+#    #+#             */
/*   Updated: 2018/12/19 16:05:19 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*cps1;
	const unsigned char	*cps2;
	size_t				i;

	cps1 = (const unsigned char *)s1;
	cps2 = (const unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (n > i + 1 && cps1[i] == cps2[i])
	{
		if (cps1[i] != cps2[i])
			return (cps1[i] - cps2[i]);
		i++;
	}
	return (cps1[i] - cps2[i]);
}
