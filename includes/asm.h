#ifndef ASM_H
# define ASM_H

# include <stdlib.h>
# include "../libft/includes/libft.h"

# define TAB_TOKEN_LEN_INIT		4
# define LEN_LTOKEN				16
# define LABELS_DEC_LEN			16
# define MAX_PARAMS				3
# define LEN_INIT_FILES			4

/*
**	EMPTY,						0
**	TOKEN_PROG_NAME,			1 .name                 data -> NULL
**	TOKEN_PROG_COMMENT,			2 .comment              data -> NULL
**
**	TOKEN_DIRECT_LABEL,			3 %:label               data -> label
**	TOKEN_DIRECT_NUMBER,		4 %number               data -> number
**	TOKEN_INDIRECT_LABEL,		5 :label                data -> label
**	TOKEN_INDIRECT_NUMBER,		6 number                data -> number
**
**	TOKEN_LABEL_DECLARATION,	7 label:                data -> label
**	TOKEN_LABEL,				8 label                 data -> label
**
**	TOKEN_STRING,				9 "string",             data -> string
**	TOKEN_COMMENT,				10 <#|;>comment\n       data -> comment
**	TOKEN_SEPARATOR_CHAR,		11 ,                    data -> NULL
**	TOKEN_EOL,					12 \n                   data -> NULL
*/

enum						e_token
{
    EMPTY,
    TOKEN_PROG_NAME,
    TOKEN_PROG_COMMENT,
    TOKEN_DIRECT_LABEL,
    TOKEN_DIRECT_NUMBER,
    TOKEN_INDIRECT_LABEL,
    TOKEN_INDIRECT_NUMBER,
    TOKEN_LABEL_DECLARATION,
    TOKEN_LABEL,
    TOKEN_STRING,
    TOKEN_COMMENT,
    TOKEN_SEPARATOR_CHAR,
    TOKEN_EOL,
};

/*
**  file_pos_line: which line the token has been created from
**  file_pose_col: which column the token has been created from
**  er: indicate if the token is valid
**  enum_token: indicate the type of token from the enum e_token
**  data: what the token represents
**  pose_octet_label_dec: the label position in case it exists
*/
typedef struct				s_token
{
    int						file_pose_line;
    int						file_pose_col;
    int						er;
    int						enum_token;
    char					*data;
    int						pose_octet_label_dec;
}                           t_token;

/*
**  len: size of the tab, depend on the number of token
**  i: index to navigate threw the tab
**  tokens: token at the "i" position
*/
typedef struct				s_tab_token
{
    int						len;
    int						i;
    t_token					*tokens;
}                           t_tab_token;

/*
**  er: indicate if an error occurred
**  file: the file given as an argument
**  tab_token: tab containing all the tokens created in the file
*/
typedef struct	    		s_lexer
{
    int						er;
    char					**file;
    t_tab_token				tab_token;
}                           t_lexer;

/*
**  er: indicate if an error occurred
**  fd: fd of the file given as an argument
**  file_name: the file name
*/
typedef struct				s_cmdl
{
    int						er;
    int						fd;
    char					*file_name;
}                           t_cmdl;

/*
**  er: indicate if an error occurred
**  nb_labels_dec: number of label for an instruction
**  labels_dec: store the token created with the lexer
**  cmd: store the instruction created with the lexer
**  nb_ast_params: number of params for an instruction
*/
typedef struct				s_ast_inst
{
    int						er;
    int						nb_labels_dec;
    t_token					labels_dec[LABELS_DEC_LEN];
    t_token					cmd;
    int						nb_ast_params;
    t_token					ast_params[MAX_PARAMS];
    struct s_ast_inst		*next;
}                           t_ast_inst;

/*
**  prog_name: program name
**  prog_comment: program comment
**  ast_inst: list of instruction declared in the program
*/
typedef struct	    		s_ast_prog
{
    char					*prog_name;
    char					*prog_comment;
    t_ast_inst				*ast_inst;
}                           t_ast_prog;

/*
**  er: indicate if an error occurred
**  ast_prog: represent all elements of the program
*/
typedef struct				s_parser
{
    int						er;
    t_ast_prog				ast_prog;
}                           t_parser;

/*
**  file: The current file
**  i_col: A column
**  i_line: A line
*/
typedef struct				s_file
{
    char					**file;
    int						*i_col;
    int						*i_line;
}                           t_file;

/*
**  cmd_input.c
*/
t_cmdl						cmd_input(int argc, char **argv);

/*
**  lexer.c
*/
t_lexer						lexer(t_cmdl cmdl);

/*
**  parser.c
*/
t_parser					parser(t_lexer lexer_res);

/*
**  ast_to_byte.c
*/
void						ast_to_byte(t_parser parser_res, char *file_name);

/*
**  ast_dote_start.c
*/
void						ast_add_dote_start(t_parser *p, t_lexer l, int *i);

/*
**  ast_add_inst.c
*/
void						ast_add_inst(t_parser *p, t_lexer l, int *i);

/*
**  ast_add_next.c
*/
void						ast_add_next(t_parser *p, t_lexer l, int *i);

/*
**  print_error.c
*/
int							asm_usage(void);
int							print_local_error
        (char **f, const int *ic, const int *il, char *m);

/*
**  line_to_token.c
*/
void						line_to_token(t_token *l, char **f, int *i);

/*
**  tab_token.c
*/
void						tab_token_multi_add(t_tab_token *t, t_token *l);

/*
**  print_tab_token.c
*/
void						print_tab_token(t_tab_token t);
void						print_token(t_token t);

/*
**  print_ast.c
*/
void						print_ast_prog(t_ast_prog a);

/*
** check_ast.c
*/
int							check_ast(t_parser p, char **f);

/*
**  check_registres.c
*/
int							check_registers(t_ast_inst *a, char **f);

/*
**  check_labeles.c
*/
int							check_labels(t_parser p, t_ast_inst *a, char **f);

/*
**  check_insts.c
*/
int							check_insts(t_ast_inst *i, char **f);

/*
**  open_new_file.c
*/
int							open_new_file(char *file_name);

/*
**  len_prog.c
*/
unsigned					prog_len(t_ast_inst *ast_inst);
int							inst_len(t_ast_inst *ast_inst);
int							len_param(int enum_token, char *cmd);

/*
**  write_header.c
*/
void						write_header(int fd, t_parser parser_res);

/*
** write_insts.c
*/
void						write_insts(int fd, t_ast_inst *ast_inst, int pos);

/*
**  write_param.c
*/
void						write_param(int f, t_token t, int d, int p);

/*
**  feed_labels.c
*/
void						inst_feed_label_dec(t_ast_inst *ast_inst, int pos);
void						insts_feed_label(t_parser p, t_ast_inst *a);

/*
**  get_direct.c
*/
t_token						get_direct(int *i_line, char **file, int *i_col);

/*
**  get_indirect.c
*/
t_token						get_indirect_number(int *il, char **f, int *ic);
t_token						get_indirect_label(int *il, char **f, int *ic);

/*
**  get_string.c
*/
t_token						get_string(int *il, char **f, int *ic);

/*
**  get_label.c
*/
t_token						get_label(int *il, char **f, int *ic);

/*
**  get_dote_start.c
*/
t_token						get_dote_start(int *il, char **f, int *ic);

/*
**  get_comment_sep.c
*/
t_token						get_separator_char(int *il, char **f, int *ic);
t_token						get_comment(int *il, char **f, int *ic);

/*
**  print_tab_token.c
*/
void						print_tab_token(t_tab_token tab_token);

/*
**  free_parser.c
*/
void						free_parser(t_parser parser_res);

/*
**  free_lexer.c
*/
void						free_lexer(t_lexer lexer_res);

/*
**  inst_add_params.c
*/
void						inst_add_params(t_ast_inst *a, t_lexer l, int *i);

#endif
