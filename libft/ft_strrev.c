/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 22:59:50 by rsaleh            #+#    #+#             */
/*   Updated: 2019/08/31 00:59:22 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_strrev(char *str, int length)
{
	int start;
	int end;

	start = 0;
	end = length - 1;
	while (start < end)
	{
		ft_charswap(*(str + start), *(str + end));
		start++;
		end--;
	}
}
