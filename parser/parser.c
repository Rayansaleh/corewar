/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 00:44:32 by rsaleh            #+#    #+#             */
/*   Updated: 2019/08/31 00:44:38 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include "../printf/printf.h"

/*
**  Function that manage the parsing
*/

t_parser	parser(t_lexer lexer_res)
{
	t_parser	parser_res;
	int			i;

	ft_bzero(&parser_res, sizeof(t_parser));
	i = 0;
	while (i <= lexer_res.tab_token.i && !parser_res.er)
		ast_add_next(&parser_res, lexer_res, &i);
	if (parser_res.er || check_ast(parser_res, lexer_res.file))
	{
		free_parser(parser_res);
		parser_res.er = 1;
		return (parser_res);
	}
	if (!parser_res.er && !prog_len(parser_res.ast_prog.ast_inst))
	{
		ft_printf("error: The program is len is 0");
		free_parser(parser_res);
		parser_res.er = 1;
		return (parser_res);
	}
	return (parser_res);
}
