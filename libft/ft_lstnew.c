/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 18:04:02 by rsaleh            #+#    #+#             */
/*   Updated: 2018/11/21 18:48:37 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*s;

	if (!(s = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!(s->content = (void*)malloc(content_size)))
			return (NULL);
		ft_memcpy(s->content, content, content_size);
		s->content_size = content_size;
	}
	else
	{
		s->content = NULL;
		s->content_size = 0;
	}
	s->next = NULL;
	return (s);
}
