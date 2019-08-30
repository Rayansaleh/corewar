/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 21:45:02 by rsaleh            #+#    #+#             */
/*   Updated: 2018/12/22 19:36:52 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if ((ptr = (char *)malloc(sizeof(char) * (len + 1))))
	{
		while (i < len)
			ptr[i++] = s[start++];
		ptr[i] = '\0';
	}
	return (ptr);
}
