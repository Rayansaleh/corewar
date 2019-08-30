/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:50:22 by rsaleh            #+#    #+#             */
/*   Updated: 2018/11/21 18:58:37 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	while (n--)
	{
		if (*(const char*)str != (char)c)
			str++;
		else
			return ((void*)str);
	}
	return (NULL);
}
