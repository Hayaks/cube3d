SRCSDIR		= ./srcs/

INCLUDESDIR	= ./includes/

SRCS		= 	$(SRCSDIR)ft_parsing.c $(SRCSDIR)get_next_line.c $(SRCSDIR)ft_parsing_map.c \
				$(SRCSDIR)ft_update.c $(SRCSDIR)ft_draw.c $(SRCSDIR)ft_imgaddr.c \
				$(SRCSDIR)ft_key.c $(SRCSDIR)ft_sprite.c $(SRCSDIR)ft_error.c \
				$(SRCSDIR)ft_move.c $(SRCSDIR)ft_vector.c $(SRCSDIR)ft_tri.c \
				$(SRCSDIR)ft_newmap.c $(SRCSDIR)ft_verif_map.c $(SRCSDIR)ft_bmp.c \
				$(SRCSDIR)ft_set_texture.c $(SRCSDIR)main.c

HEADER		= 	$(INCLUDESDIR)cub3d.h

OBJS		= $(SRCS:.c=.o)

INCLUDES	= -I$(HEADER)

NAME		= cub3d

CC			= gcc
LIB			= ar -rcs
RM			= rm -f

CFLAGS		= -Wall -Werror -Wextra

$(NAME):	$(OBJS)
			@make -C ./libft/
			@cp ./libft/libft.a .
			$(CC) $(CFLAGS) -I.(ou header) -L. -lft -lmlx -framework OpenGl -framework Appkit $^ -o $@
			$(LIB) $(NAME) $(OBJS)
			gcc -Wall -Werror -Wextra -lmlx -framework OpenGl -framework Appkit $(NAME)

$(OBJS):
			$(CC) $(CFLAGS) -c $(SRCS)

bonus:		bonus_objs
			@make -C ./libft/
			@cp ./libft/libft.a .
			$(CC) $(CFLAGS) -DBONUS=1 -I.(ou header) -L. -lft -lmlx -framework OpenGl -framework Appkit $(OBJS) -o $(NAME)

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