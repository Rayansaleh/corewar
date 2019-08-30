/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:39:50 by rsaleh            #+#    #+#             */
/*   Updated: 2019/01/09 19:33:45 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	char		*s1;
	char		*s2;

	s1 = (char*)str1;
	s2 = (char*)str2;
	while (n--)
		s1[n] = s2[n];
	return (str1);
}
