/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:24:31 by rsaleh            #+#    #+#             */
/*   Updated: 2018/11/21 18:56:44 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	j;

	if (!*needle)
		return ((char*)haystack);
	if (!needle)
		return ((char*)haystack);
	j = ft_strlen(needle);
	while (*haystack)
	{
		if (ft_strncmp(haystack, needle, j) == 0)
			return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
