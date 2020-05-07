/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 17:17:16 by thaley            #+#    #+#             */
/*   Updated: 2019/01/06 17:17:16 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*s_new;
	char	*scp;

	if (s == NULL || (!(scp = ft_strnew(ft_strlen(s)))))
		return (NULL);
	if (!scp)
		return (NULL);
	s_new = scp;
	while (*s)
	{
		*scp = f(*s);
		scp++;
		s++;
	}
	return (s_new);
}
