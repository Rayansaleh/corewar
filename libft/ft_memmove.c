/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:03:23 by rsaleh            #+#    #+#             */
/*   Updated: 2018/11/21 18:58:00 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	unsigned char *s1;
	unsigned char *s2;

	s1 = (unsigned char*)str1;
	s2 = (unsigned char*)str2;
	if (s2 < s1)
		while (n--)
			s1[n] = s2[n];
	else
		ft_memcpy(s1, s2, n);
	return (str1);
}
