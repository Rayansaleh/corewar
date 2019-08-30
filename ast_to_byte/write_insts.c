#include "../includes/asm.h"
#include "../includes/op.h"
#include <unistd.h>

/*
**  Write the parameters into a char so it can be identify
*/
void		write_octet_param(int fd, t_ast_inst *ast_inst)
{
	int				i;
	unsigned char	codect;

	i = 0;
	codect = 0;
	while (i < ast_inst->nb_ast_params)
	{
		if (ast_inst->ast_params[i].enum_token == TOKEN_DIRECT_NUMBER ||
			ast_inst->ast_params[i].enum_token == TOKEN_DIRECT_LABEL)
			codect |= (0b10 << ((3 - i) * 2));
		else if (ast_inst->ast_params[i].enum_token == TOKEN_LABEL)
			codect |= (0b01 << ((3 - i) * 2));
		else
			codect |= (0b11 << ((3 - i) * 2));
		i++;
	}
	write(fd, &codect, 1);
}

/*
**  Write the params in the new file in converted format
*/
void		write_params(int fd, t_ast_inst *ast_inst, int dir_size_2, int pos)
{
	int i;

	i = 0;
	while (i < ast_inst->nb_ast_params)
	{
		write_param(fd, ast_inst->ast_params[i], dir_size_2, pos);
		i++;
	}
}

/*
**  Write the instruction in the new file in converted format
*/
void		write_inst(int fd, t_ast_inst *ast_inst, int pos)
{
	t_op op;

	if (!ast_inst->cmd.enum_token)
		return ;
	op = get_op_name(ast_inst->cmd.data);
	write(fd, &op.opcode, 1);
	if (op.octet_param)
		write_octet_param(fd, ast_inst);
	write_params(fd, ast_inst, op.dir_size_2, pos);
}

void		write_insts(int fd, t_ast_inst *ast_inst, int pos)
{
	if (!ast_inst)
		return ;
	write_inst(fd, ast_inst, pos);
	write_insts(fd, ast_inst->next, pos + inst_len(ast_inst));
}
