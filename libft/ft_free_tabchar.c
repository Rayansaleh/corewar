#include <stdlib.h>

void	ft_free_tabchar(char **tab)
{
    int i;

    i = 0;
    while (tab && tab[i])
    {
        free(tab[i]);
        i++;
    }
    if (tab)
        free(tab);
}