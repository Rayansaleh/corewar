/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 21:55:58 by rsaleh            #+#    #+#             */
/*   Updated: 2019/01/06 17:32:08 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = -1;
	if ((ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + \
						ft_strlen(s2) + 1))))
	{
		while (s1[++j])
			ptr[j] = s1[j];
		while (s2[i])
			ptr[j++] = s2[i++];
		ptr[j] = '\0';
	}
	return (ptr);
}
