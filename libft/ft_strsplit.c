/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 12:11:39 by rsaleh            #+#    #+#             */
/*   Updated: 2018/12/17 21:31:29 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		nbwords;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	nbwords = ft_nbwords((char*)s, c);
	if (!(str = (char**)malloc(sizeof(char*) * nbwords + 1)))
		return (NULL);
	while (nbwords--)
	{
		while (*s == c && *s)
			s++;
		str[i] = ft_strsub((char*)s, 0, ft_strclength((char*)s, c));
		s += ft_strclength((char*)s, c);
		i++;
	}
	str[i] = NULL;
	return (str);
}
