/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 00:44:15 by rsaleh            #+#    #+#             */
/*   Updated: 2019/08/31 00:44:19 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
**  Free everything that has been store to parse
**  In order to avoid leaks
*/

void	free_ast_inst(t_ast_inst *ast_inst)
{
	int		i;

	i = 0;
	if (!ast_inst)
		return ;
	free_ast_inst(ast_inst->next);
	while (i < ast_inst->nb_labels_dec)
	{
		ft_memdel((void **)&(ast_inst->labels_dec[i].data));
		i++;
	}
	ft_memdel((void **)&(ast_inst->cmd.data));
	i = 0;
	while (i < ast_inst->nb_ast_params)
	{
		ft_memdel((void **)&(ast_inst->ast_params[i].data));
		i++;
	}
	ft_memdel((void **)&ast_inst);
}

void	free_parser(t_parser parser_res)
{
	ft_memdel((void **)&(parser_res.ast_prog.prog_comment));
	ft_memdel((void **)&(parser_res.ast_prog.prog_name));
	free_ast_inst(parser_res.ast_prog.ast_inst);
}
