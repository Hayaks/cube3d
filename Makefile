SRCSDIR		= ./srcs/

INCLUDESDIR	= ./includes/

SRCS		= 	$(SRCSDIR)parsing.c $(SRCSDIR)get_next_line.c

HEADER		= 	$(INCLUDESDIR)cub3d.h

OBJS		= $(SRCS:.c=.o)

INCLUDES	= -I$(HEADER)

NAME		= cub3d.a

CC			= gcc
LIB			= ar -rcs
RM			= rm -f

CFLAGS		= -Wall -Werror -Wextra

.c.o:	
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(INCLUDES)

$(NAME):	$(OBJS)
			@make -C ./libft/
			@cp ./libft/libft.a ./$(NAME)
			$(LIB) $(NAME) $(OBJS)

all:		$(NAME)

clean: 		
			$(RM) $(OBJS)
			@make clean -C ./libft/

fclean:		clean
			$(RM) $(NAME)
			@make fclean -C ./libft/

re:			fclean all

.PHONY:		all clean fclean re