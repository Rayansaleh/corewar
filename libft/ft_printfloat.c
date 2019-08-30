/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfloat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 19:24:35 by rsaleh            #+#    #+#             */
/*   Updated: 2019/08/31 01:00:04 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdio.h>

void	ft_printfloat(double nb, unsigned int i)
{
	int tmp;

	tmp = (int)nb;
	ft_putnbr(tmp);
	nb -= tmp;
	if (i > 0)
		write(1, ".", 1);
	while (i > 0)
	{
		nb *= 10;
		tmp = (int)nb;
		ft_putnbr(tmp);
		nb -= tmp;
		i--;
	}
}
