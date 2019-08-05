/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 22:10:48 by rsaleh            #+#    #+#             */
/*   Updated: 2018/12/17 21:31:38 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	start;
	unsigned int	end;

	if (!s)
		return (NULL);
	start = 0;
	end = ft_strlen(s) - 1;
	while ((s[start] == ' ' || s[start] == '\t' ||
				s[start] == '\n') && s[start])
		start++;
	if (s[start] == '\0')
		return (ft_strnew(0));
	while ((s[end] == ' ' || s[end] == '\t' ||
				s[end] == '\n') && end > start && s[end])
		end--;
	return (ft_strsub(s, start, (end - start + 1)));
}
