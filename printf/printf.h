/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 19:07:37 by rsaleh            #+#    #+#             */
/*   Updated: 2019/08/30 23:55:39 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdint.h>
# include <stdarg.h>
# include <stdio.h>

typedef	struct	s_printf
{
	int			len;
	int			width;
	int			precision;
	va_list		ap;
	int			fi;
	int			finalsize;
	char		buff[64];
	int			buffi;
	int			ff;
	char		arg;
	char		*format;
}				t_printf;

# define DIEZ			(1 << 0)
# define SPACE			(1 << 1)
# define PLUS			(1 << 2)
# define MINUS			(1 << 3)
# define ZERO			(1 << 4)
# define SHORT			(1 << 5)
# define CHAR			(1 << 6)
# define LONG			(1 << 7)
# define LONGLONG		(1 << 8)
# define ISPRECI		(1 << 9)
# define ISADDRESS		(1 << 10)

void			create_buffer(void *newbuff, size_t size, t_printf *pf);
int				ft_printf(const char *format, ...);
void			get_flag(t_printf *pf);
void			ft_printf_itoa(intmax_t nb, int len, t_printf *pf);
void			printf_putchar(t_printf *pf);
uintmax_t		unsigned_int_flag(int flag, unsigned int arg);
void			printf_putaddr(t_printf *pf);
void			printf_putstr(t_printf *pf);
void			no_valid_arg(t_printf *pf);
void			put_width(t_printf *pf, int val);
char			*string_converter(char *ap, int conv);
void			ft_printf_itoa_base(uintmax_t nb, uintmax_t tmp,
			t_printf *pf, int base);
int				ft_is_flag(t_printf *pf);
int				ft_is_arg(t_printf *pf);
void			printf_putnbr(t_printf *pf);
void			printf_putunbr(int base, t_printf *pf);

#endif
