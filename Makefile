SRCSDIR		= ./

INCLUDESDIR	= ./includes/

LIBDIR		= ./libft/

MLXDIR		= ./mlx/

LIBFT		= $(LIBDIR)libft.a

SRCS		= 	$(SRCSDIR)ft_parsing.c $(SRCSDIR)get_next_line.c $(SRCSDIR)ft_parsing_map.c \
				$(SRCSDIR)ft_update.c $(SRCSDIR)ft_draw.c $(SRCSDIR)ft_imgaddr.c \
				$(SRCSDIR)ft_key.c $(SRCSDIR)ft_sp.c $(SRCSDIR)ft_error.c \
				$(SRCSDIR)ft_move.c $(SRCSDIR)ft_vector.c $(SRCSDIR)ft_tri.c \
				$(SRCSDIR)ft_newmap.c $(SRCSDIR)ft_verif_map.c $(SRCSDIR)ft_bmp.c \
				$(SRCSDIR)ft_set_texture.c $(SRCSDIR)ft_verif_color.c $(SRCSDIR)main.c \
				$(SRCSDIR)ft_verif_window.c $(SRCSDIR)ft_stop.c

HEADER		= 	$(INCLUDESDIR)cub3d.h

OBJS		= $(SRCS:.c=.o)

INCLUDES	= -I$(HEADER)

NAME		= Cub3D

CC			= clang
LIB			= ar -rcs
RM			= rm -f

CFLAGS		= -Wall -Werror -Wextra
MLX_FLAG	= -L$(MLXDIR) -lmlx -L/usr/include/../lib -lXext -lX11 -lm -lbsd -Iincludes

$(NAME):	$(OBJS)
			@make -C ./libft/
			@cp ./libft/libft.a .
			$(CC) $(CFLAGS) $(SRCSDIR)*.o -o $(NAME) $(LIBFT) $(MLX_FLAG)

.c.o:		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(INCLUDES)

bonus:		bonus_objs
			@make -C ./libft/
			@cp ./libft/libft.a .
			$(CC) $(CFLAGS) -DBONUS=1 $(SRCSDIR)*.o -o $(NAME) $(LIBFT) $(MLX_FLAG)

bonus_objs:
			$(CC) $(CFLAGS) -DBONUS=1 -c $(SRCS)

all:		$(NAME)

clean: 		
			$(RM) $(OBJS)
			@make clean -C ./libft/

fclean:		clean
			$(RM) $(NAME)
			@make fclean -C ./libft/

re:			fclean all

.PHONY:		all clean fclean re