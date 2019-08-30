/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_add_next.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 00:42:54 by rsaleh            #+#    #+#             */
/*   Updated: 2019/08/31 00:43:01 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	ast_add_next(t_parser *parser_res, t_lexer lexer_res, int *i)
{
	if (lexer_res.tab_token.tokens[*i].enum_token == TOKEN_PROG_NAME ||
			lexer_res.tab_token.tokens[*i].enum_token == TOKEN_PROG_COMMENT)
		ast_add_dote_start(parser_res, lexer_res, i);
	else if (lexer_res.tab_token.tokens[*i].enum_token == TOKEN_EOL ||
			lexer_res.tab_token.tokens[*i].enum_token == TOKEN_COMMENT)
		(*i)++;
	else if (lexer_res.tab_token.tokens[*i].enum_token ==
					TOKEN_LABEL_DECLARATION ||
			lexer_res.tab_token.tokens[*i].enum_token == TOKEN_LABEL)
		ast_add_inst(parser_res, lexer_res, i);
	else
	{
		print_local_error(lexer_res.file,
						&(lexer_res.tab_token.tokens[*i].file_pose_col),
						&(lexer_res.tab_token.tokens[*i].file_pose_line),
						"parser: Unexpected token");
		parser_res->er = 1;
	}
}
