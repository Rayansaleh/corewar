/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 05:10:24 by rsaleh            #+#    #+#             */
/*   Updated: 2018/11/21 18:47:04 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t len;

	i = 0;
	len = ft_strlen(src);
	if (size == 0)
		return (len);
	while (i < size - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}
