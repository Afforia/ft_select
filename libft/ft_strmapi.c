/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 18:19:22 by thaley            #+#    #+#             */
/*   Updated: 2019/01/06 18:19:24 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*s_new;

	i = 0;
	if (s == NULL || (!(s_new = ft_strnew(ft_strlen(s)))))
		return (NULL);
	while (s[i])
	{
		s_new[i] = f(i, s[i]);
		i++;
	}
	return (s_new);
}
