#include "../includes/cub3d.h"

void    ft_free_s(t_struct *info)
{
    int i;

    i = 0;
    while (i < info->nb)
    {
        if (info->sprites[i] != NULL)
            free(info->sprites[i]);
        i++;
    }
    if (info->sprites != NULL)
        free(info->sprites);
}

void    ft_free_text(text_param *text)
{
    if (text->no != NULL)
    free(text->no);
    if (text->so != NULL)
    free(text->so);
    if (text->we != NULL)
    free(text->we);
    if (text->ea != NULL)
    free(text->ea);
    if (text->s != NULL)
    free(text->s);
    if (text->c != NULL)
    free(text->c);
    if (text->f != NULL)
    free(text->f);
    if (text != NULL)
    free(text);
}

void    ft_free_info(t_struct *info)
{
    int i;

    i = 0;
    while (i < info->i)
    {
        if (info->map[i] != NULL)
            free(info->map[i]);
        i++;
    }
    if (info->map != NULL)
        free(info->map);
    //if (info->type != NULL)
        //free(info->type);
    if (info->no != NULL)
        free(info->no);
    if (info->so != NULL)
        free(info->so);
    if (info->we != NULL)
        free(info->we);
    if (info->ea != NULL)
        free(info->ea);
    if (info->s != NULL)
        free(info->s);
    if (info->f != NULL)
        free(info->f);
    if (info->c != NULL)
        free(info->c);
    if (info != NULL)
        free(info);
}

void    ft_free_mlx(mlx_param *mlx)
{
    if (mlx->perp != NULL)
        free(mlx->perp);
    if (mlx != NULL)
        free(mlx);
}

void    ft_error(int i, t_struct *info)
{   
    if (i > 0)
        write(1,"Erreur\n", 8);
    if (i == 1)
        write(1,"Probleme de malloc\n", 20);
    if (i == 2)
        write(1,"Mauvaise map\n", 14);
    if (i == 3)
        write(1,"Mauvais argument\n", 18);
    if (info->sp != NULL)
        free(info->sp);
    if (info->d != NULL)
        free(info->d);
    ft_free_s(info);
    ft_free_text(info->text);
    ft_free_mlx(info->mlx);
    ft_free_info(info);
    //verifier si les textures sont bons
                system("leaks a.out");
    while(1)
    {
        
    }
    exit(0);
}