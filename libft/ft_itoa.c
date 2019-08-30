/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:14:50 by rsaleh            #+#    #+#             */
/*   Updated: 2018/11/21 18:49:46 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		neg;
	int		len;

	neg = 0;
	len = ft_count(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len--] = '\0';
	if (n < 0)
	{
		n = -n;
		neg = 1;
	}
	while (len >= 0)
	{
		str[len] = (n % 10) + '0';
		len--;
		n /= 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
