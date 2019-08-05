#include "../includes/asm.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	open_file(char *file)
{
	int 	fd;
	int 	len;
	char	*new_file;

	len = ft_strlen(file);
	if (!(new_file = ft_strnew(len + 2)))
		return (0);
	ft_strcpy(new_file, file);
	new_file[len - 1] = 'c';
	new_file[len] = 'o';
	new_file[len + 1] = 'r';
	fd = open(new_file, O_CREAT | O_RDWR, S_IRWXG);
	free(new_file);
	return (fd);
}
