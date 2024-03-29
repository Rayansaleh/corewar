/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_lst_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 00:54:49 by rsaleh            #+#    #+#             */
/*   Updated: 2019/08/31 00:54:54 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_get_lst_size(t_list *list)
{
	t_list	*l;
	int		tr;

	l = list;
	tr = 0;
	while (l)
	{
		tr++;
		l = l->next;
	}
	return (tr);
}
