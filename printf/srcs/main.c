/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:29:57 by rsaleh            #+#    #+#             */
/*   Updated: 2019/01/11 21:44:39 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"
#include "../libft/includes/libft.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	ac = 0;
	printf("vrai:%.12c\n", 'r');
	ft_printf("faux:%.12c\n", 'r');
	return (0);
}
