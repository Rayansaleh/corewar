#include "includes/asm.h"

int	main(int ac, char **av)
{
    t_arg arg;

    arg = check_arg(ac - 1, av + 1);
    if (arg.error == -1)
    {
        printf("Something is wrong\n");
        return (-1);
    }
	return (0);
}
