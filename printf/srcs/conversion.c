/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 16:06:34 by rsaleh            #+#    #+#             */
/*   Updated: 2019/08/30 23:56:28 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"
#include "../../libft/includes/libft.h"
#include <stdio.h>

int	ft_is_arg(t_printf *pf)
{
	if (*pf->format == 'd' || *pf->format == 'i' || *pf->format == 'o' ||
			*pf->format == 'x' || *pf->format == 'X' || *pf->format == 'u' ||
			*pf->format == 's' || *pf->format == 'p' || *pf->format == 'c' ||
			*pf->format == 'f')
		return (1);
	return (0);
}
