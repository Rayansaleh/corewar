#include "../includes/asm.h"
#include "../includes/op.h"
#include "../printf/printf.h"
#include <unistd.h>

/*
**  Write the header with op.h and op.c which are given in the subject
**  Header is compose of magical number, a name, a size and comments
**  The magical number is given in op.h
**  The prog name was already stored in the parser so its just copied
**  The prog size is defined by a precise function
**  The comments where already stored in the parser so its just copied
*/
void	write_header(int fd, t_parser parser_res)
{
	t_header header;

	ft_bzero(&header, sizeof(t_header));
	header.magic = COREWAR_EXEC_MAGIC;
	swap_4(&(header.magic));
	ft_strcpy(header.prog_name, parser_res.ast_prog.prog_name);
	header.prog_size = prog_len(parser_res.ast_prog.ast_inst);
	swap_4(&(header.prog_size));
	if (parser_res.ast_prog.prog_comment)
		ft_strcpy(header.comment, parser_res.ast_prog.prog_comment);
	if (write(fd, &header, sizeof(t_header)) != sizeof(t_header))
	{
		ft_printf("Unexpected error, can't write the file.cor\n");
		free_parser(parser_res);
		exit(1);
	}
}
