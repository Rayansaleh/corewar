/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_to_byte.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 00:49:49 by rsaleh            #+#    #+#             */
/*   Updated: 2019/08/31 00:50:21 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
**	o
*/

void	ast_to_byte(t_parser parser_res, char *file_name)
{
	int	fd;

	fd = open_new_file(file_name);
	if (fd < 0)
		return ;
	inst_feed_label_dec(parser_res.ast_prog.ast_inst, 0);
	insts_feed_label(parser_res, parser_res.ast_prog.ast_inst);
	write_header(fd, parser_res);
	write_insts(fd, parser_res.ast_prog.ast_inst, 0);
}
