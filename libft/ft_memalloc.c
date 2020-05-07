/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 19:06:00 by thaley            #+#    #+#             */
/*   Updated: 2019/01/04 19:06:02 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	*x;
	void	*cp;

	if (!(x = (size_t*)malloc(size * sizeof(size_t))))
		return (NULL);
	cp = x;
	while (size)
	{
		*x = '\0';
		x++;
		size--;
	}
	return (cp);
}
