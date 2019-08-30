#include "../includes/asm.h"

/*
**  Once the lexer has been used and all the tokens are created
**  and stored in a tab everything is freed in order to avoid leeks
*/
void	free_lexer(t_lexer lexer_res)
{
	int		i;

	i = 0;
	if (lexer_res.file)
		ft_free_tabchar(lexer_res.file);
	while (i <= lexer_res.tab_token.i)
	{
		ft_memdel((void **)&(lexer_res.tab_token.tokens[i].data));
		i++;
	}
	ft_memdel((void **)&lexer_res.tab_token.tokens);
}