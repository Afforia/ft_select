/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 05:08:47 by thaley            #+#    #+#             */
/*   Updated: 2018/12/02 05:08:48 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*scp;

	i = 0;
	while (s1[i] != '\0')
		i++;
	if (i == 0)
	{
		if (!(scp = (char*)malloc(sizeof(char) * (1))))
			return (NULL);
	}
	else if (!(scp = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (*(s1 + i) != '\0')
	{
		*(scp + i) = *(s1 + i);
		i++;
	}
	*(scp + i++) = '\0';
	return (scp);
}
