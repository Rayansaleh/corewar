#include "includes/asm.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
    t_cmdl		cmdl;
    t_lexer		lexer_res;
    t_parser	parser_res;

    cmdl = cmd_input(argc - 1, argv + 1);
    if (cmdl.er)
        return (1);
    lexer_res = lexer(cmdl);
    close(cmdl.fd);
    if (lexer_res.er)
        return (1);
    parser_res = parser(lexer_res);
    free_lexer(lexer_res);
    if (parser_res.er)
        return (1);
    ast_to_byte(parser_res, cmdl.file_name);
    free_parser(parser_res);
    return (0);
}