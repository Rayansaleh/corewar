/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:16:42 by rsaleh            #+#    #+#             */
/*   Updated: 2018/11/09 15:42:31 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *str1, const char *str2)
{
	unsigned char *s1;
	unsigned char *s2;

	s1 = (unsigned char*)str1;
	s2 = (unsigned char*)str2;
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}
