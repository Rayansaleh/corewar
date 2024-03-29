/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 01:11:03 by rsaleh            #+#    #+#             */
/*   Updated: 2019/08/31 01:13:23 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include "../printf/printf.h"

void	print_ast_inst(t_ast_inst *ast_inst)
{
	int	i;

	if (!ast_inst)
		return ;
	i = 0;
	while (i < ast_inst->nb_labels_dec)
	{
		print_token(ast_inst->labels_dec[i]);
		i++;
	}
	i = 0;
	ft_printf("%s ", ast_inst->cmd.data);
	while (i < ast_inst->nb_ast_params)
	{
		print_token(ast_inst->ast_params[i]);
		i++;
	}
	ft_printf("\n");
	print_ast_inst(ast_inst->next);
}

void	print_ast_prog(t_ast_prog ast_prog)
{
	ft_printf(".name: %s\n", ast_prog.prog_name);
	ft_printf(".comment: %s\n", ast_prog.prog_comment);
	print_ast_inst(ast_prog.ast_inst);
}
