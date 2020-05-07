/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 19:44:51 by thaley            #+#    #+#             */
/*   Updated: 2019/01/06 19:44:52 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		i_cp;
	char	*cps;

	i = 0;
	i_cp = -1;
	if (s == NULL)
		return (NULL);
	j = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && j > i)
		j--;
	if (j < i)
		return (ft_strnew(0));
	if (!(cps = ft_strnew(j - i + 1)))
		return (NULL);
	while (i + (++i_cp) <= j)
		cps[i_cp] = s[i + i_cp];
	return (cps);
}
