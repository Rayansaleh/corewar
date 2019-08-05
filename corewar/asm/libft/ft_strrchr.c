/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:06:41 by rsaleh            #+#    #+#             */
/*   Updated: 2018/11/21 18:57:29 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char *s;

	s = NULL;
	while (*str)
	{
		if (*str == (char)c)
			s = (char*)str;
		str++;
	}
	if (*str == (char)c)
		s = (char*)str;
	return (s);
}
