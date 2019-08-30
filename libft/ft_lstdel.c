/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 01:27:33 by rsaleh            #+#    #+#             */
/*   Updated: 2018/11/21 18:48:18 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del) (void *, size_t))
{
	t_list *next;

	next = (*alst)->next;
	ft_lstdelone(alst, del);
	if (next)
		ft_lstdel(&next, del);
}
