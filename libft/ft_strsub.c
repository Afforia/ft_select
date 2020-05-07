/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <thaley@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 18:50:19 by thaley            #+#    #+#             */
/*   Updated: 2019/03/11 19:38:44 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*scp;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	else if (!(scp = ft_strnew(len)))
		return (NULL);
	while (i < len)
	{
		scp[i] = s[start];
		start++;
		i++;
	}
	scp[i] = '\0';
	return (scp);
}
