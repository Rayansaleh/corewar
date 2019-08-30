/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 01:06:45 by rsaleh            #+#    #+#             */
/*   Updated: 2019/08/31 01:10:42 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	swap_char(unsigned char *a, unsigned char *b)
{
	unsigned char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void		swap_2(unsigned short int *to_swap)
{
	unsigned char	*pt;

	pt = (unsigned char *)to_swap;
	swap_char(pt, pt + 1);
}

void		swap_4(unsigned int *to_swap)
{
	unsigned char *pt;

	pt = (unsigned char *)to_swap;
	swap_char(pt, pt + 3);
	swap_char(pt + 1, pt + 2);
}
