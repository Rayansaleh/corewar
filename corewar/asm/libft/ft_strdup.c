/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:01:44 by rsaleh            #+#    #+#             */
/*   Updated: 2018/11/21 18:59:35 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup(const char *str)
{
	char	*tr;
	size_t	i;

	tr = (char *)malloc((1 + ft_strlen(str)) * sizeof(char));
	if (tr == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		tr[i] = str[i];
		i++;
	}
	tr[i] = '\0';
	return (tr);
}
