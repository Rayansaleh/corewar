/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:41:14 by rsaleh            #+#    #+#             */
/*   Updated: 2019/08/31 00:49:16 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/includes/libft.h"
#include "../printf.h"
#include <stdio.h>

char	*ft_printf_itoa_base(uintmax_t nb, int base, char c)
{
	int		i;
	char	*ret;
	char	*tmp;

	i = 1;
	while (ft_power(base, i) - 1 < nb)
		i++;
	ret = ft_strnew(i);
	while (i-- > 0)
	{
		ret[i] = (nb % base) + (nb % base > 9 ? c - 10 : '0');
		nb /= base;
	}
	if (*ret == '0' && ret[1])
	{
		tmp = ret;
		while (*ret == '0')
			ret++;
		ret = ft_strdup(ret);
		free(tmp);
	}
	return (ret);
}

char	*ft_create_flag_list(char *list, char other_flag)
{
	int		len;

	len = ft_strlen(list);
	list[len] = other_flag;
	list[len + 1] = '\0';
	return (list);
}

int		ft_width(const char *format)
{
	int	end;
	int	ret;

	end = 0;
	ret = 0;
	while (format[end] >= '0' && format[end] <= '9')
		end++;
	ret = ft_atoi(ft_strsub(format, 0, end));
	return (ret);
}
