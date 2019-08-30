#include "../includes/asm.h"

/*
**  If the label is valid it's stored
**  The rest of the instruction
**  Will be check later in the program
*/
void		inst_add_labels_dec(t_ast_inst *ast_inst, t_lexer lexer_res, int *i)
{
	while (lexer_res.tab_token.tokens[*i].enum_token == TOKEN_LABEL_DECLARATION
		&& !ast_inst->er)
	{
		if (ast_inst->nb_labels_dec + 1 >= LABELS_DEC_LEN)
		{
			print_local_error(lexer_res.file,
							&(lexer_res.tab_token.tokens[*i].file_pose_col),
							&(lexer_res.tab_token.tokens[*i].file_pose_line),
							"paser: Too many label before one cmd");
			ast_inst->er = 1;
			return ;
		}
		ast_inst->labels_dec[ast_inst->nb_labels_dec] =
				lexer_res.tab_token.tokens[*i];
		ast_inst->labels_dec[ast_inst->nb_labels_dec].data = ft_strdup(
				lexer_res.tab_token.tokens[*i].data);
		ast_inst->nb_labels_dec++;
		(*i)++;
		while (lexer_res.tab_token.tokens[*i].enum_token == TOKEN_EOL ||
			lexer_res.tab_token.tokens[*i].enum_token == TOKEN_COMMENT)
			(*i)++;
	}
}

/*
**  If this the first instruction it just create a link
**  If it isn't we create a new link at the end of the list
**  It the error to the parser result in order to know where it went wrong
*/
void		add_inst_to_parser_res(t_parser *parser_res, t_ast_inst ast_inst)
{
	t_ast_inst	*current;
	t_ast_inst	*to_add;

	to_add = ft_memalloc(sizeof(t_ast_inst));
	*to_add = ast_inst;
	if (!parser_res->ast_prog.ast_inst)
		parser_res->ast_prog.ast_inst = to_add;
	else
	{
		current = parser_res->ast_prog.ast_inst;
		while (current->next)
			current = current->next;
		current->next = to_add;
	}
}

/*
**  If an error has been spotted previously
**  If there is label without any instruction
**  If a label is spotted but hasn't been mark as a token
**  It imply a error in the program
*/
static int	ast_add_inst_check_error(t_parser *parser_res,
		t_lexer lexer_res, int *i, t_ast_inst ast_inst)
{
	if (ast_inst.er)
	{
		parser_res->er = 1;
		add_inst_to_parser_res(parser_res, ast_inst);
		return (1);
	}
	if (ast_inst.nb_labels_dec > 0 && lexer_res.tab_token.i < (*i))
	{
		add_inst_to_parser_res(parser_res, ast_inst);
		return (1);
	}
	if (lexer_res.tab_token.tokens[*i].enum_token != TOKEN_LABEL)
	{
		print_local_error(lexer_res.file,
			&(lexer_res.tab_token.tokens[*i].file_pose_col),
			&(lexer_res.tab_token.tokens[*i].file_pose_line),
			"parser: Need a command");
		parser_res->er = 1;
		add_inst_to_parser_res(parser_res, ast_inst);
		return (1);
	}
	return (0);
}

/*
**  Add a new instruction to check
*/
void		ast_add_inst(t_parser *parser_res, t_lexer lexer_res, int *i)
{
	t_ast_inst	ast_inst;

	ft_bzero(&ast_inst, sizeof(t_ast_inst));
	inst_add_labels_dec(&ast_inst, lexer_res, i);
	if (ast_add_inst_check_error(parser_res, lexer_res, i, ast_inst))
		return ;
	ast_inst.cmd = lexer_res.tab_token.tokens[*i];
	ast_inst.cmd.data = ft_strdup(lexer_res.tab_token.tokens[*i].data);
	(*i)++;
	inst_add_params(&ast_inst, lexer_res, i);
	if (ast_inst.er)
		parser_res->er = 1;
	add_inst_to_parser_res(parser_res, ast_inst);
}
