/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 00:28:48 by rsaleh            #+#    #+#             */
/*   Updated: 2019/08/31 00:31:25 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"
#include "printf/printf.h"
#include <fcntl.h>

/*
**  Check if the file is valid
*/

static	t_cmdl	check_erro_cmdl(int argc, char **argv, t_cmdl *cmdl)
{
	size_t	len;

	if (argc != 1)
	{
		asm_usage();
		cmdl->er = 1;
		return (*cmdl);
	}
	len = ft_strlen(argv[0]);
	if (len < 3 ||
			argv[0][len - 1] != 's' ||
			argv[0][len - 2] != '.')
	{
		ft_printf("file name must finish with .s and not be empty\n");
		cmdl->er = 1;
		return (*cmdl);
	}
	return (*cmdl);
}

/*
**  Store the fd of the file given as argument
**  And store its name has well
*/

t_cmdl			cmd_input(int argc, char **argv)
{
	t_cmdl	cmdl;

	ft_bzero(&cmdl, sizeof(t_cmdl));
	check_erro_cmdl(argc, argv, &cmdl);
	if (cmdl.er)
		return (cmdl);
	cmdl.fd = open(argv[0], O_RDONLY);
	if (cmdl.fd < 0)
	{
		ft_printf("No file name %s\n", argv[0]);
		cmdl.er = 1;
	}
	cmdl.file_name = argv[0];
	return (cmdl);
}
