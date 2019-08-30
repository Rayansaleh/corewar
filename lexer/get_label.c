#include "../includes/asm.h"
#include "../includes/op.h"

/*
**  If we found a standard label neither direct or indirect
**  we identify it and store it.
*/
t_token	get_label(int *i_line, char **file, int *i_col)
{
	t_token	token;
	int		i;

	ft_bzero(&token, sizeof(t_token));
	i = 0;
	token.enum_token = TOKEN_LABEL;
	token.data = ft_strdup(file[*i_line] + *i_col);
	while (token.data[i] && ft_strchr(LABEL_CHARS, token.data[i]))
		i++;
	token.data[i] = '\0';
	if (file[*i_line][*i_col + i] == ':')
	{
		token.enum_token = TOKEN_LABEL_DECLARATION;
		(*i_col)++;
	}
	*i_col = *i_col + i;
	return (token);
}
