/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 12:30:36 by thaley            #+#    #+#             */
/*   Updated: 2018/12/04 12:30:38 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*bonus;
	int		flag;

	bonus = NULL;
	flag = 0;
	while (*s != '\0')
	{
		if (*s == c)
		{
			bonus = (char *)s;
			flag = 1;
		}
		s++;
	}
	if (flag == 1)
		return (bonus);
	else if (c == '\0')
		return ((char *)s);
	else
		return (NULL);
}
