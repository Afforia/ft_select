/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaley <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 20:34:02 by thaley            #+#    #+#             */
/*   Updated: 2019/01/11 20:34:03 by thaley           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print(char *str, int min, int count, int n)
{
	if (min != 0)
		*str = '-';
	if (n < 0)
		while (count > 0)
		{
			str[count + min - 1] = -(n % 10) + '0';
			count--;
			n /= 10;
		}
	else
		while (count > 0)
		{
			str[count + min - 1] = n % 10 + '0';
			count--;
			n /= 10;
		}
}

char		*ft_itoa(int n)
{
	char	*str;
	int		count;
	int		min;
	int		n_len;

	count = 1;
	min = 0;
	n_len = n;
	if (n < 0)
		min = 1;
	while (n_len / 10)
	{
		n_len /= 10;
		count++;
	}
	if (!(str = ft_strnew(count + min)))
		return (NULL);
	ft_print(str, min, count, n);
	return (str);
}
