/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dote_start.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 00:37:05 by rsaleh            #+#    #+#             */
/*   Updated: 2019/08/31 00:37:13 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
**  If we found a dote, check if its a name or a comment
*/

t_token	get_dote_start(int *i_line, char **file, int *i_col)
{
	t_token	token;

	ft_bzero(&token, sizeof(t_token));
	if (ft_strnequ(".name", file[*i_line] + *i_col, 5))
	{
		token.enum_token = TOKEN_PROG_NAME;
		*i_col = *i_col + 5;
		return (token);
	}
	if (ft_strnequ(".comment", file[*i_line] + *i_col, 8))
	{
		token.enum_token = TOKEN_PROG_COMMENT;
		*i_col = *i_col + 8;
		return (token);
	}
	print_local_error(file, i_col, i_line,
					"lexer: Dote start, unexpected word after '.'");
	token.er = 1;
	return (token);
}
