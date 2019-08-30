/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:47:49 by rsaleh            #+#    #+#             */
/*   Updated: 2019/01/16 17:15:29 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

uintmax_t		ft_power(uintmax_t nb, int power)
{
	uintmax_t result;

	result = nb;
	power--;
	while (power--)
		result *= nb;
	return (result);
}
