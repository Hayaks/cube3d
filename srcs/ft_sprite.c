#include "../includes/cub3d.h"

ft_sprite(t_struct *info, int mapx, int mapy, int i)
{
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

    info->sprites[i]->dist = ((info->mlx->posx - mapx) * (info->mlx->posx - mapx) + (info->mlx->posy - mapy) * (info->mlx->posy - mapy));
    spritex = mapx + 0.5 - info->mlx->posx;
    spritey = mapy + 0.5 - info->mlx->posy;
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

    //recupere l'adresse de l'image en cours

    while (drawstartx < drawendx)
    {
        y = drawstarty;
        texx = (int)((256 * (drawstartx - (-spritewidth / 2 + spritescreenx)) * 64 / info->text->sx) / 256);
        if(transformy > 0 && drawstartx >= 0 && drawstartx <= info->x && transformy < perpwalldist)
            while (y < drawendy)
            {
                d = y * 256 - info->y * 128+ spriteheight * 128;
                texy = ((d * info->text->sy) / spriteheight) / 256;
                img[drawstartx + info->x * y] = info->text->s[info->text->sx * texy + texx]; 
            }
        drawstartx++; 
    }
}