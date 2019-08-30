/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 22:47:08 by rsaleh            #+#    #+#             */
/*   Updated: 2018/12/18 14:40:18 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/libft.h"

char	*ft_itoa_base(int num, char *str, int base)
{
	int i = 0;
	int neg = 0;
	int rem = 0;

	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return str;
	}
	if (num < 0 && base == 10)
	{
		neg = 1;
		num = -num;
	}
	while (num)
	{
		rem = num % base; 
		str[i++] = (rem > 9)? (rem - 10) + 'a' : rem + '0'; 
		num = num/base;
	}

	if (neg)
		str[i++] = '-';
	str[i] = '\0';
	ft_strrev(str, i);
	return (str);
}
