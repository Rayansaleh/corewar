/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:18:06 by rsaleh            #+#    #+#             */
/*   Updated: 2018/11/21 18:59:03 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int i;
	int j;

	i = 0;
	if (!(dest || src))
		return (NULL);
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0' && n > 0)
	{
		dest[i] = src[j];
		n--;
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
