#include "../includes/cub3d.h"

void    ft_error(int i)
{   
    write (1,"Erreur\n", 6);
    if (i == 1)
        write (1,"Mauvais argument\n", 18);
    exit(0);
}