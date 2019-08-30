/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 20:19:24 by rsaleh            #+#    #+#             */
/*   Updated: 2018/11/23 14:46:13 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnew(size_t size)
{
	char *ptr;

	ptr = (char *)malloc(sizeof(char) * (size + 1));
	if (ptr)
		ft_memset(ptr, '\0', size + 1);
	return (ptr);
}
