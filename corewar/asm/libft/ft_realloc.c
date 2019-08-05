/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 17:32:22 by rsaleh            #+#    #+#             */
/*   Updated: 2019/01/06 17:34:30 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <stdio.h>

char	*ft_realloc(char *src, size_t new_size)
{
	char	*tmp;

	if (!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (NULL);
	ft_strcpy(tmp, src);
	free(src);
	if (!(src = (char *)malloc(sizeof(char) * new_size)))
		return (NULL);
	src[new_size - 1] = '\0';
	ft_strcpy(src, tmp);
	free(tmp);
	return (src);
}
