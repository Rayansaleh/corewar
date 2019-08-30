/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:50:32 by rsaleh            #+#    #+#             */
/*   Updated: 2018/11/21 18:58:52 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t k;

	k = 0;
	i = ft_strlen(dest);
	j = ft_strlen(src);
	if (size <= i)
		return (j + size);
	while (i + k < size - 1 && src[k])
	{
		dest[i + k] = src[k];
		k++;
	}
	dest[i + k] = '\0';
	return (i + j);
}
