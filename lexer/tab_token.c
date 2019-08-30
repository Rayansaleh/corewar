/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaleh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 00:38:34 by rsaleh            #+#    #+#             */
/*   Updated: 2019/08/31 00:38:59 by rsaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
**  Called only once to initialize the tab which will contain all tokens
*/

void	init_tab_token(t_tab_token *tab_token)
{
	tab_token->len = TAB_TOKEN_LEN_INIT;
	tab_token->i = -1;
	tab_token->tokens = ft_memalloc(sizeof(t_token) * tab_token->len);
}

/*
**  Add a single token in a tab (called by tab_token_multi_add)
*/

void	tab_token_add(t_tab_token *tab_token, t_token tken)
{
	if (!tab_token->tokens)
		init_tab_token(tab_token);
	tab_token->i++;
	if (tab_token->i >= tab_token->len)
	{
		tab_token->tokens = ft_realloc(tab_token->tokens,
		sizeof(t_token) * tab_token->len, sizeof(t_token) * tab_token->len * 2);
		tab_token->len = tab_token->len * 2;
	}
	tab_token->tokens[tab_token->i] = tken;
}

/*
**  Add to a tab all tokens found on a line
*/

void	tab_token_multi_add(t_tab_token *tab_token, t_token *ltken)
{
	int	i;

	if (!tab_token->tokens)
		init_tab_token(tab_token);
	i = 0;
	while (1)
	{
		tab_token_add(tab_token, ltken[i]);
		if (ltken[i].enum_token == TOKEN_EOL)
			break ;
		i++;
	}
}
