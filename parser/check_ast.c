/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 00:43:19 by rsaleh            #+#    #+#             */
/*   Updated: 2019/08/31 00:43:26 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include "../includes/op.h"
#include "../printf/printf.h"

/*
**  Check basic error such as
**  Does the program exists
**  Does it have a name
**  Is the name valid
**  If there is comments are they valid
*/

int		check_ast(t_parser parser_res, char **file)
{
	if (!parser_res.ast_prog.prog_name ||
			!ft_strlen(parser_res.ast_prog.prog_name))
		return (ft_printf("error: The program must have a name\n"));
	else if (ft_strlen(parser_res.ast_prog.prog_name) > PROG_NAME_LENGTH)
		return (ft_printf(
			"error: Program name can't be contain more than 128 char\n"));
	else if (parser_res.ast_prog.prog_comment &&
			ft_strlen(parser_res.ast_prog.prog_comment) > COMMENT_LENGTH)
		return (ft_printf(
			"error: Program comment can't be contain more than 2048 char\n"));
	else if (!prog_len(parser_res.ast_prog.ast_inst))
		return (ft_printf("error: The program is empty\n"));
	else if (check_registers(parser_res.ast_prog.ast_inst, file) ||
			check_labels(parser_res, parser_res.ast_prog.ast_inst, file) ||
			check_insts(parser_res.ast_prog.ast_inst, file))
		return (1);
	return (0);
}
