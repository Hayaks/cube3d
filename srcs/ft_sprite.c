#include "../includes/cub3d.h"

void    ft_vide(t_struct *info, int *img)
{
    int i;

    i = 0;
    while (i < (info->x * info->y))
    {
        if (img[i] == 0)
			img[i] = 0xFFFFFFFF;
		i++;
    }
}

int     *ft_tri(t_struct *info, int *final)
{
    int     i;
    int     j;
    float   *tab;
    float   *temp;

    if (!(tab = malloc(sizeof(*tab) * (info->nb))))
        exit(0);
    if (!(temp = malloc(sizeof(*temp) * (info->nb))))
        exit(0);    
    i = 0;
    j = 0;
    while (i < info->nb)
    {
        tab[j] = info->sprites[i]->dist;
        j++;
        i++;
    }
    i = 0;
    j = 0;
    while ((j + 1) < info->nb)
    {
        if (tab[j] < tab[j + 1])
        {
            temp[i] = tab[j];
            tab[j] = tab[j + 1];
            tab[j + 1] = temp[i];
            i++;
            j = 0;
        }
        j++;
    }
    i = 0;
    j = 0;
    while (j < info->nb)
    {
        while ((int)tab[j] != (int)info->sprites[i]->dist)
            i++;
        final[j] = i;
        info->sprites[i]->dist = 0.0;
        i = 0;
        j++;
    }
    free(tab);
    final[j] = -1;
    return (final);
}

void    ft_sprite(t_struct *info)
{
    int     i;
    int     y;
    int     d;
    float   spritex;
    float   spritey;
    float   invdet;
    float   transformx;
    float   transformy;
    int     spritescreenx;
    int     spriteheight;
    int     spritewidth;
    int     drawstarty;
    int     drawendy;
    int     drawstartx;
    int     drawendx;
    int     texy;
    int     texx;
    int     *final;

    if (!(final = malloc(sizeof(*final) * (info->nb))))
        exit(0);
    i = 0;
    y = 0; 
    while (y < info->nb)
    {
        info->sprites[y]->dist = ((int)info->mlx->posx - info->sprites[y]->x) * ((int)info->mlx->posx - info->sprites[y]->x)+ ((int)info->mlx->posy - info->sprites[y]->y) * ((int)info->mlx->posy - info->sprites[i]->y);
        y++;
    }
    final = ft_tri(info, final);
    while (i < info->nb)
    {
        //Trouver le plus loin du joueur a afficher
        info->sprites[final[i]]->img = ft_imgaddr(info->mlx->img);
        spritex = info->sprites[final[i]]->x + 0.5 - info->mlx->posx;
        spritey = info->sprites[final[i]]->y + 0.5 - info->mlx->posy;
        invdet = 1.0 / (info->mlx->planex * info->mlx->diry - info->mlx->planey * info->mlx->dirx);
        transformx = invdet * (info->mlx->diry * spritex - info->mlx->dirx * spritey);
        transformy = invdet * (-info->mlx->planey * spritex + info->mlx->planex * spritey);
        spritescreenx = (int)((info->x / 2) * (1.0 + transformx / transformy));

        spriteheight = abs((int)(info->y / transformy));
        drawstarty = -spriteheight / 2 + info->y / 2;
        if (drawstarty < 0)
            drawstarty = 0;
        drawendy = spriteheight / 2 + info->y / 2;
        if (drawendy < 0)
            drawendy = 0;

        spritewidth = abs((int)(info->y / transformy));
        drawstartx = -spritewidth / 2 + spritescreenx;
        if (drawstartx < 0)
            drawstartx = 0;
        drawendx = spritewidth / 2 + spritescreenx;
        if (drawendx < 0)
            drawendx = 0;
        while (drawstartx < drawendx)
        {
            y = drawstarty;
            texx = (int)((256 * (drawstartx - (-spritewidth / 2 + spritescreenx)) * info->text->sx / spritewidth) / 256);
            if (transformy > 0 && drawstartx > 0 && drawstartx < info->x && transformy < info->mlx->perp[drawstartx])
                while (y < drawendy && y < info->y)
                {
                    d = y * 256 - info->y * 128 + spriteheight * 128;
                    texy = ((d * info->text->sy) / spriteheight) / 256;
                    if (info->text->s[info->text->sx * texy + texx] != 0)
                        info->sprites[final[i]]->img[drawstartx + info->x * y] = info->text->s[info->text->sx * texy + texx]; 
                    y++;
                }
            drawstartx++; 
        }
        info->sprites[final[i]]->dist = 0.0;
        i++;
    }
}