/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 00:37:52 by rsaleh            #+#    #+#             */
/*   Updated: 2019/09/05 21:36:18 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include "../includes/get_next_line.h"
#include "../printf/printf.h"

/*
**  Used to read and store the file
*/

void			feed_lexer_files(t_lexer *lexer_res, int fd)
{
	int		len_files;
	int		i;
	char	*line;
	int		res;

	i = 0;
	len_files = LEN_INIT_FILES;
	lexer_res->file = ft_memalloc(sizeof(char *) * len_files);
	while ((res = get_next_line(fd, &line)) > 0)
	{
		if (i + 1 >= len_files)
		{
			lexer_res->file = ft_realloc(lexer_res->file,
			len_files * sizeof(char *),
			len_files * 2 * sizeof(char *));
			len_files *= 2;
		}
		lexer_res->file[i] = line;
		i++;
	}
	if (res < 0)
	{
		ft_printf("Unexpected error with gnl\n");
		lexer_res->er = 1;
	}
}

/*
**  In case of error free the lexer to avoid leeks
**  And mention that a occurred so the program stops
*/

static t_lexer	free_error(t_lexer *lexer_res)
{
	free_lexer(*lexer_res);
	lexer_res->er = 1;
	return (*lexer_res);
}

/*
**  Print a message before freeing the lexer
*/

static t_lexer	free_print(t_lexer *lexer_res)
{
	ft_printf("lexer: the program is empty\n");
	return (free_error(lexer_res));
}

/*
**  Used to convert a given file into a list of token
**  The process go through different steps
**  Read and store the file
**  Mark tokens on each line
**  Store those tokens
*/

t_lexer			lexer(t_cmdl cmdl)
{
	t_lexer		lexer_res;
	t_token		ltken[LEN_LTOKEN];
	int			i_line;

	ft_bzero(&lexer_res, sizeof(t_lexer));
	lexer_res.tab_token.i = -1;
	i_line = 0;
	feed_lexer_files(&lexer_res, cmdl.fd);
	if (lexer_res.er)
		return (free_error(&lexer_res));
	while (lexer_res.file[i_line])
	{
		ft_bzero(ltken, sizeof(t_token) * LEN_LTOKEN);
		line_to_token(ltken, lexer_res.file, &i_line);
		tab_token_multi_add(&(lexer_res.tab_token), ltken);
		if (ltken[0].er)
			return (free_error(&lexer_res));
		i_line++;
	}
	if (!lexer_res.file[0] || lexer_res.tab_token.i < 0)
		return (free_print(&lexer_res));
	return (lexer_res);
}
