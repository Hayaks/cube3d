#include "../includes/cub3d.h"

void    ft_error(int i)
{   
    if (i > 0)
        write(1,"Erreur\n", 8);
    if (i == 1)
        write(1,"Probleme de malloc\n", 20);
    if (i == 2)
        write(1,"Mauvaise map\n", 14);
    if (i == 3)
        write(1,"Mauvais argument\n", 18);
    //fonction pour free 
    exit(0);
}