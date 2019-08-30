/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 00:56:37 by rsaleh            #+#    #+#             */
/*   Updated: 2018/11/21 18:48:53 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstdelone(t_list **alst, void (*del) (void*, size_t))
{
	if (*alst)
		del((*alst)->content, (*alst)->content_size);
	ft_memdel((void**)alst);
}
