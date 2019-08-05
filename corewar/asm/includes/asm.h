#ifndef ASM_H
# define ASM_H

# include "../libft/includes/libft.h"

typedef struct		s_arg
{
	int		        fd;
	int		        error;
	char		    *file;
}			        t_arg;

int			        open_file(char *file);
t_arg               check_arg(int ac, char **av);
t_arg               check_arg_format(int ac, char **av, t_arg arg);

#endif
