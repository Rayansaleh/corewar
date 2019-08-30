/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 22:59:50 by rsaleh            #+#    #+#             */
/*   Updated: 2018/12/18 11:57:52 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/libft.h"

void ft_strrev(char *str, int length) 
{ 
	int start;
	int end;

	start = 0;
   	end = length -1; 
	while (start < end) 
	{ 
		ft_charswap(*(str + start), *(str+end)); 
		start++; 
		end--; 
	} 
} 
