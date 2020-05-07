/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 20:18:13 by thaley            #+#    #+#             */
/*   Updated: 2019/01/06 20:18:15 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_arrlen(char const *s, char c)
{
	int len;
	int i;

	i = 0;
	len = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			len++;
		while (s[i] != c && s[i])
			i++;
	}
	return (len);
}

static int		ft_findstr(char const *s, char c, int i)
{
	int len;

	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i])
	{
		i++;
		len++;
	}
	return (len);
}

static char		**ft_freestr(char **str, int arr)
{
	arr--;
	if (arr >= 0)
	{
		free(str[arr]);
		arr--;
	}
	free(str[arr]);
	return (NULL);
}

static char		**ft_crstr(char const *s, char **str_arr, int i_s, char c)
{
	int		i_str;
	int		len;
	int		arr;

	arr = 0;
	while (s[i_s])
	{
		while (s[i_s] == c)
			i_s++;
		if (s[i_s] != c && s[i_s] != '\0')
		{
			len = ft_findstr(s, c, i_s);
			if (!(str_arr[arr] = ft_strnew(len)))
				ft_freestr(str_arr, arr);
			i_str = -1;
			while (++i_str < len)
				str_arr[arr][i_str] = s[i_s++];
			str_arr[arr][i_str] = '\0';
			arr++;
		}
	}
	str_arr[arr] = NULL;
	return (str_arr);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str_arr;
	int		i_s;
	int		len;

	str_arr = NULL;
	i_s = 0;
	len = 0;
	if (!s)
		return (NULL);
	len = ft_arrlen(s, c);
	if (!(str_arr = (char **)malloc(sizeof(*str_arr) * (len + 1))))
		return (NULL);
	str_arr = ft_crstr(s, str_arr, i_s, c);
	return (str_arr);
}
