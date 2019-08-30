/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_dote_start.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 00:40:35 by rsaleh            #+#    #+#             */
/*   Updated: 2019/08/31 00:40:44 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
**  Print a custom error message
*/

static void	print_and_set_error(t_parser *parser_res, t_lexer *lexer_res,
								int *i, char *msg)
{
	print_local_error(lexer_res->file,
					&(lexer_res->tab_token.tokens[*i].file_pose_col),
					&(lexer_res->tab_token.tokens[*i].file_pose_line),
					msg);
	parser_res->er = 1;
}

/*
**  Detect different error that can occur after a dote
*/

void		ast_add_dote_start(t_parser *parser_res, t_lexer lexer_res, int *i)
{
	char	*error_msg;

	error_msg = NULL;
	if (*i + 1 > lexer_res.tab_token.i)
		error_msg = "parser: Dote start, not String found";
	else if (lexer_res.tab_token.tokens[*i + 1].enum_token != TOKEN_STRING)
		error_msg = "parser: Dote start, not String found";
	else if (lexer_res.tab_token.tokens[*i].enum_token == TOKEN_PROG_NAME &&
			parser_res->ast_prog.prog_name)
		error_msg = "parser: Dote start, you can use only one '.name'";
	else if (lexer_res.tab_token.tokens[*i].enum_token == TOKEN_PROG_COMMENT &&
			parser_res->ast_prog.prog_comment)
		error_msg = "parser: Dote start, you can use only one '.comment'";
	if (error_msg)
		print_and_set_error(parser_res, &lexer_res, i, error_msg);
	else if (lexer_res.tab_token.tokens[*i].enum_token == TOKEN_PROG_COMMENT)
		parser_res->ast_prog.prog_comment = ft_strdup(
				lexer_res.tab_token.tokens[*i + 1].data);
	else
		parser_res->ast_prog.prog_name = ft_strdup(
				lexer_res.tab_token.tokens[*i + 1].data);
	*i = *i + 3;
}
