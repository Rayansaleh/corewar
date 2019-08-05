#include "../includes/asm.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


t_arg 	    check_arg_format(int ac, char **av, t_arg arg)
{
    int     len;

	if (ac != 1)
    {
        printf("Wrong nb of arguments\n");
	    arg.error = -1;
        return (arg);
    }
	len = ft_strlen(av[0]);
	if (len < 3 || av[0][len - 1] != 's' || av[0][len -2] != '.')
    {
	    printf("Wrong extension\n");
	    arg.error = -1;
        return (arg);
    }
    return (arg);
}

t_arg	check_arg(int ac, char **av)
{
	t_arg	arg;
	
	arg.fd = 0;
	arg.error = 0;
	check_arg_format(ac, av, arg);
	if (arg.error == -1)
        return (arg);
	if (!(arg.fd = open(av[0], O_RDONLY)))
        arg.error = -1;
	arg.file = av[0];
    return (arg);
}	
