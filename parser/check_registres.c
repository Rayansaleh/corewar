/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_registres.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 00:42:08 by rsaleh            #+#    #+#             */
/*   Updated: 2019/08/31 00:42:14 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include "../includes/op.h"

/*
**  Check if register exists
*/

int		is_register(char *label)
{
	int		reg_num;
	int		er;

	er = 0;
	if (label[0] != 'r')
		return (0);
	label++;
	reg_num = ft_atoi_only(label, &er);
	if (er || reg_num <= 0 || reg_num > REG_NUMBER)
		return (0);
	return (1);
}

/*
**  Check if the register passed as a param is valid
*/

int		check_registers(t_ast_inst *ast_inst, char **file)
{
	int		i;

	if (!ast_inst)
		return (0);
	i = 0;
	while (i < ast_inst->nb_ast_params)
	{
		if (ast_inst->ast_params[i].enum_token == TOKEN_LABEL &&
			!is_register(ast_inst->ast_params[i].data))
		{
			print_local_error(file, &(ast_inst->ast_params[i].file_pose_col),
							&(ast_inst->ast_params[i].file_pose_line),
							"no valid param register");
			return (1);
		}
		i++;
	}
	return (check_registers(ast_inst->next, file));
}
