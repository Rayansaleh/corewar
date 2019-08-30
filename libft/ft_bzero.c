/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:59:17 by rsaleh            #+#    #+#             */
/*   Updated: 2018/11/21 18:45:42 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_bzero(void *s, int nbyte)
{
	unsigned char	*str;
	int				i;

	i = -1;
	str = (unsigned char *)s;
	while (++i < nbyte)
		str[i] = '\0';
}
