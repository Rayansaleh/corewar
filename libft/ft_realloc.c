/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 17:32:22 by rsaleh            #+#    #+#             */
/*   Updated: 2019/01/06 17:34:30 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

void	*ft_realloc(void *pt, int sizeold, int new_size)
{
    void	*to_do;

    if (sizeold < 0 || new_size < 0)
        return (NULL);
    if (sizeold >= new_size)
        return (pt);
    to_do = ft_memalloc((size_t)new_size);
    ft_memmove(to_do, pt, (size_t)sizeold);
    free(pt);
    return (to_do);
}
