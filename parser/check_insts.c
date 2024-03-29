/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_insts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 00:40:57 by rsaleh            #+#    #+#             */
/*   Updated: 2019/08/31 00:41:52 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include "../includes/op.h"
#include "../printf/printf.h"

/*
**  Check if the param has a valid type
**  By comparing it to all possible type
*/

int			check_param(t_token token, int t_arg, char **file)
{
	if ((t_arg & T_DIR) &&
		(token.enum_token == TOKEN_DIRECT_LABEL ||
		token.enum_token == TOKEN_DIRECT_NUMBER))
		return (0);
	if ((t_arg & T_IND) &&
		(token.enum_token == TOKEN_INDIRECT_LABEL ||
		token.enum_token == TOKEN_INDIRECT_NUMBER))
		return (0);
	if ((t_arg & T_REG) &&
		token.enum_token == TOKEN_LABEL)
		return (0);
	print_local_error(file, &(token.file_pose_col),
					&(token.file_pose_line),
					"error: bad parameter");
	return (1);
}

/*
**  Check the cmd (instruction)
**  Check the number of params and their validity
*/

int			check_cmd(t_ast_inst *inst, t_op op_desc, char **file)
{
	int		i;

	if (inst->nb_ast_params != op_desc.nb_arg)
	{
		print_local_error(file, &(inst->cmd.file_pose_col),
						&(inst->cmd.file_pose_line),
						"error: bad number of param");
		return (1);
	}
	i = 0;
	while (i < inst->nb_ast_params)
	{
		if (check_param(inst->ast_params[i], op_desc.args[i], file))
			return (1);
		i++;
	}
	return (0);
}

/*
**  In case label isn't at the right spot the following
**  Instruction is executed (function due to a lack of line)
*/

static int	print_aux(t_ast_inst *inst, char **file)
{
	print_local_error(file,
		&(inst->labels_dec[inst->nb_labels_dec - 1].file_pose_col),
		&(inst->labels_dec[inst->nb_labels_dec - 1].file_pose_line),
		"error: label as not cmd and is not in the end");
	return (1);
}

/*
**  Check if the label's position is valid
**  And if the cmd(instruction) is valid as well
*/

int			check_inst(t_ast_inst *inst, char **file)
{
	int		i;

	i = 0;
	if (!inst->nb_labels_dec && !inst->cmd.enum_token)
	{
		ft_printf("Unexpected error: 1\n");
		return (1);
	}
	if (!inst->cmd.enum_token && inst->next)
		return (print_aux(inst, file));
	else if (!inst->cmd.enum_token && !inst->next)
		return (0);
	while (i < OP_TAB_LENGTH)
	{
		if (ft_strequ(gopt()[i].name, inst->cmd.data))
			return (check_cmd(inst, gopt()[i], file));
		i++;
	}
	print_local_error(file, &(inst->cmd.file_pose_col),
					&(inst->cmd.file_pose_line),
					"error: unknow command");
	return (1);
}

int			check_insts(t_ast_inst *inst, char **file)
{
	if (!inst)
		return (0);
	if (check_inst(inst, file))
		return (1);
	return (check_insts(inst->next, file));
}
