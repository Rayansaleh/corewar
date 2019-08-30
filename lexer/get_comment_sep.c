/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_comment_sep.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 00:36:43 by rsaleh            #+#    #+#             */
/*   Updated: 2019/08/31 00:36:51 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
**  If in the file we found a separator, we identify it as one
*/

t_token	get_separator_char(int *i_line, char **file, int *i_col)
{
	t_token token;

	(void)i_line;
	(void)file;
	ft_bzero(&token, sizeof(t_token));
	token.enum_token = TOKEN_SEPARATOR_CHAR;
	(*i_col)++;
	return (token);
}

/*
**  If in the file we detect a comment, we identify it as one
**  Then we store the comment in a (char*)
*/

t_token	get_comment(int *i_line, char **file, int *i_col)
{
	t_token token;

	ft_bzero(&token, sizeof(t_token));
	(*i_col)++;
	token.enum_token = TOKEN_COMMENT;
	token.data = ft_strdup(file[*i_line] + *i_col);
	*i_col = *i_col + (int)ft_strlen(token.data);
	return (token);
}
