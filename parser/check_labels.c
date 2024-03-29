/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_labels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 00:43:47 by rsaleh            #+#    #+#             */
/*   Updated: 2019/08/31 00:44:02 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
**  Simply check if the label exists
*/

int		check_label_if_exist(t_ast_inst *ast_inst, const char *to_find)
{
	int	i;

	if (!ast_inst)
		return (1);
	i = 0;
	while (i < ast_inst->nb_labels_dec)
	{
		if (ft_strequ(to_find, ast_inst->labels_dec[i].data))
			return (0);
		i++;
	}
	return (check_label_if_exist(ast_inst->next, to_find));
}

/*
**  Check if a label has been declare as a token
**  And if it has been declared
*/

int		check_labels_params(t_parser parser_res,
							t_ast_inst *ast_inst, char **file)
{
	int		i;

	if (!ast_inst)
		return (0);
	i = 0;
	while (i < ast_inst->nb_ast_params)
	{
		if ((ast_inst->ast_params[i].enum_token == TOKEN_DIRECT_LABEL ||
			ast_inst->ast_params[i].enum_token == TOKEN_INDIRECT_LABEL) &&
			check_label_if_exist(parser_res.ast_prog.ast_inst,
								ast_inst->ast_params[i].data))
		{
			print_local_error(file, &(ast_inst->ast_params[i].file_pose_col),
							&(ast_inst->ast_params[i].file_pose_line),
							"label is not declare");
			return (1);
		}
		i++;
	}
	return (check_labels(parser_res, ast_inst->next, file));
}

/*
**  Check if same label appear twice
*/

int		check_inst_label_dec(t_ast_inst *ast_inst, char **file)
{
	int		i;
	int		j;

	i = 0;
	while (i < ast_inst->nb_labels_dec)
	{
		j = i + 1;
		while (j < ast_inst->nb_labels_dec)
		{
			if (ft_strequ(ast_inst->labels_dec[i].data,
						ast_inst->labels_dec[j].data))
			{
				print_local_error(file,
								&(ast_inst->labels_dec[j].file_pose_col),
								&(ast_inst->labels_dec[j].file_pose_line),
								"label already declared");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

/*
**  Check if there is two label for the same instruction
*/

int		check_labels_dec(t_parser parser_res, t_ast_inst *ast_inst, char **file)
{
	int	i;

	if (!ast_inst)
		return (0);
	if (check_inst_label_dec(ast_inst, file))
		return (1);
	i = 0;
	while (i < ast_inst->nb_labels_dec)
	{
		if (!check_label_if_exist(ast_inst->next, ast_inst->labels_dec[i].data))
		{
			print_local_error(file, &(ast_inst->labels_dec[i].file_pose_col),
							&(ast_inst->labels_dec[i].file_pose_line),
							"label is declared more than one time");
			return (1);
		}
		i++;
	}
	return (check_labels_dec(parser_res, ast_inst->next, file));
}

int		check_labels(t_parser parser_res, t_ast_inst *ast_inst, char **file)
{
	return (check_labels_dec(parser_res, ast_inst, file) ||
			check_labels_params(parser_res, ast_inst, file));
}
