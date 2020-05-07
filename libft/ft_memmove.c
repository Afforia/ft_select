/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 14:27:19 by thaley            #+#    #+#             */
/*   Updated: 2018/12/19 14:27:22 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*cpsrc;
	char		*cpdst;

	cpdst = (char *)dst;
	cpsrc = (const char *)src;
	if (cpdst > cpsrc)
	{
		cpdst = cpdst + (len - 1);
		cpsrc = cpsrc + (len - 1);
		while (len-- > 0)
			*cpdst-- = *cpsrc--;
	}
	else
	{
		while (len-- > 0)
			*cpdst++ = *cpsrc++;
	}
	return (dst);
}
