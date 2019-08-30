/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_only.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 00:54:29 by rsaleh            #+#    #+#             */
/*   Updated: 2019/08/31 00:54:34 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_atoi_only(const char *str, int *er)
{
	int i;
	int n;
	int signe;

	i = 0;
	n = 0;
	signe = 1;
	while (ft_isblank(str[i]))
		i++;
	if (str[i] == '-')
	{
		signe = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		n = n * 10 + str[i++] - '0';
		if ((signe == 1 && n < 0) || (signe == -1 && n < 0 && -n != n))
			*er = 1;
	}
	if (str[i])
		*er = 1;
	return (n * signe);
}
