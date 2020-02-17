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

void    ft_sprite(t_struct *info)
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

    //info->sprites[i]->dist = ((info->mlx->posx - mapx) * (info->mlx->posx - mapx) + (info->mlx->posy - mapy) * (info->mlx->posy - mapy));
    info->sprites[0]->newimg = mlx_new_image(info->mlx->init, info->x, info->y);
    info->sprites[0]->img = ft_imgaddr(info->sprites[0]->newimg);
    spritex = info->sprites[0]->x + 0.5 - info->mlx->posx;
    spritey = info->sprites[0]->y + 0.5 - info->mlx->posy;
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
                info->sprites[0]->img[drawstartx + info->x * y] = info->text->s[info->text->sx * texy + texx]; 
                y++;
            }
        drawstartx++; 
    }
    ft_vide(info, info->sprites[0]->img);
    mlx_put_image_to_window(info->mlx->init, info->mlx->window, info->sprites[0]->newimg, 0, 0);
}