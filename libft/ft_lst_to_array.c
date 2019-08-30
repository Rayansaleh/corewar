/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 00:55:30 by rsaleh            #+#    #+#             */
/*   Updated: 2019/08/31 00:55:32 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	**ft_lst_to_array(t_list *list, int *size)
{
	int		i;
	t_list	*l;
	t_list	**tr;

	*size = ft_get_lst_size(list);
	tr = (t_list **)malloc(sizeof(t_list *) * (*size));
	if (tr == NULL)
		return (NULL);
	l = list;
	i = 0;
	while (l)
	{
		tr[i] = l;
		i++;
		l = l->next;
	}
	return (tr);
}
