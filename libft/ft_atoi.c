/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:54:24 by rsaleh            #+#    #+#             */
/*   Updated: 2018/11/09 15:57:55 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int i;
	int neg;
	int nbr;

	i = 0;
	neg = 0;
	nbr = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\v') ||
			(str[i] == '\n') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == 45)
		neg = 1;
	if (str[i] == 45 || str[i] == 43)
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		nbr *= 10;
		nbr += (str[i] - 48);
		i++;
	}
	if (neg == 1)
		return (-nbr);
	else
		return (nbr);
}
