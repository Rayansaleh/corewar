/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feed_label.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 00:50:30 by rsaleh            #+#    #+#             */
/*   Updated: 2019/08/31 00:50:42 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include "../printf/printf.h"

/*
**  Sets all labels positions to 0
*/

void	inst_feed_label_dec(t_ast_inst *ast_inst, int pos)
{
	int i;

	if (!ast_inst)
		return ;
	i = 0;
	while (i < ast_inst->nb_labels_dec)
	{
		ast_inst->labels_dec[i].pose_octet_label_dec = pos;
		i++;
	}
	inst_feed_label_dec(ast_inst->next, pos + inst_len(ast_inst));
}

/*
**  Compare labels stored in the structure and the current one
**  to know its position
*/

int		find_label_pos(t_ast_inst *ast_inst, char *label)
{
	int i;

	if (!ast_inst)
	{
		ft_printf("Unexcepted error: 2\n");
		return (0);
	}
	i = 0;
	while (i < ast_inst->nb_labels_dec)
	{
		if (ft_strequ(ast_inst->labels_dec[i].data, label))
			return (ast_inst->labels_dec[i].pose_octet_label_dec);
		i++;
	}
	return (find_label_pos(ast_inst->next, label));
}

/*
**  Store find and store label position
*/

void	token_label_feed_pos(t_parser parser_res, t_token *token)
{
	int pose;

	pose = find_label_pos(parser_res.ast_prog.ast_inst, token->data);
	token->pose_octet_label_dec = pose;
}

/*
**  If there is label we call a function find its position
*/

void	inst_feed_label(t_parser parser_res, t_ast_inst *ast_inst)
{
	int i;

	i = 0;
	while (i < ast_inst->nb_ast_params)
	{
		if (ast_inst->ast_params[i].enum_token == TOKEN_INDIRECT_LABEL ||
				ast_inst->ast_params[i].enum_token == TOKEN_DIRECT_LABEL)
			token_label_feed_pos(parser_res, ast_inst->ast_params + i);
		i++;
	}
}

void	insts_feed_label(t_parser parser_res, t_ast_inst *ast_inst)
{
	if (!ast_inst)
		return ;
	inst_feed_label(parser_res, ast_inst);
	insts_feed_label(parser_res, ast_inst->next);
}
