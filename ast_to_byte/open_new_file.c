/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_new_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 00:51:25 by rsaleh            #+#    #+#             */
/*   Updated: 2019/08/31 00:51:30 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include "../printf/printf.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/*
**  Open a new file and change its extension to .cor
*/

int		open_new_file(char *file_name)
{
	int		fd;
	size_t	len;
	char	*new_file_name;

	len = ft_strlen(file_name);
	new_file_name = ft_strnew(len + 3);
	ft_strcpy(new_file_name, file_name);
	new_file_name[len + 1] = 'r';
	new_file_name[len] = 'o';
	new_file_name[len - 1] = 'c';
	fd = open(new_file_name, O_CREAT | O_RDWR, S_IRWXU | S_IRWXG | S_IRWXO);
	if (fd > 0)
		ft_printf("result will write in %s\n", new_file_name);
	else
		ft_printf("Unexpected error, can't write the file.cor\n");
	free(new_file_name);
	return (fd);
}
