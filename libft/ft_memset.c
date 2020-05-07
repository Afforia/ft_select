/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 11:11:18 by thaley            #+#    #+#             */
/*   Updated: 2018/12/11 11:11:19 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*fill;

	fill = (unsigned char *)b;
	while (len)
	{
		*fill = (unsigned char)c;
		fill++;
		len--;
	}
	return (b);
}
