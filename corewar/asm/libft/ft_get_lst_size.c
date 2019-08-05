#include "includes/libft.h"

int		ft_get_lst_size(t_list *list)
{
	t_list	*l;
	int		tr;

	l = list;
	tr = 0;
	while (l)
	{
		tr++;
		l = l->next;
	}
	return (tr);
}
