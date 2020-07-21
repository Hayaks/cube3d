SRCSDIR		= ./

BONUSDIR	= ./

INCLUDESDIR	= ./

SRCS		= 	$(SRCSDIR)ft_atoi.c $(SRCSDIR)ft_isalnum.c $(SRCSDIR)ft_isalpha.c \
			$(SRCSDIR)ft_isascii.c $(SRCSDIR)ft_isdigit.c $(SRCSDIR)ft_isprint.c \
			$(SRCSDIR)ft_memset.c $(SRCSDIR)ft_strchr.c $(SRCSDIR)ft_strlcat.c \
			$(SRCSDIR)ft_strlcpy.c $(SRCSDIR)ft_strlen.c $(SRCSDIR)ft_strncmp.c \
			$(SRCSDIR)ft_strrchr.c $(SRCSDIR)ft_tolower.c $(SRCSDIR)ft_toupper.c \
			$(SRCSDIR)ft_bzero.c $(SRCSDIR)ft_memcpy.c $(SRCSDIR)ft_memccpy.c \
			$(SRCSDIR)ft_memmove.c $(SRCSDIR)ft_memchr.c $(SRCSDIR)ft_memcmp.c \
			$(SRCSDIR)ft_strnstr.c $(SRCSDIR)ft_calloc.c \
			$(SRCSDIR)ft_strdup.c $(SRCSDIR)ft_substr.c $(SRCSDIR)ft_strjoin.c \
			$(SRCSDIR)ft_strtrim.c $(SRCSDIR)ft_putchar_fd.c $(SRCSDIR)ft_putstr_fd.c \
			$(SRCSDIR)ft_putendl_fd.c $(SRCSDIR)ft_putnbr_fd.c $(SRCSDIR)ft_itoa.c \
			$(SRCSDIR)ft_strmapi.c $(SRCSDIR)ft_split.c $(SRCSDIR)ft_itoa_base.c

SRCSBONUS	= $(BONUSDIR)ft_lstnew.c $(BONUSDIR)ft_lstadd_front.c $(BONUSDIR)ft_lstsize.c \
			  $(BONUSDIR)ft_lstlast.c $(BONUSDIR)ft_lstadd_back.c $(BONUSDIR)ft_lstdelone.c \
			  $(BONUSDIR)ft_lstclear.c

HEADER		= 	$(INCLUDESDIR)libft.h

OBJS		= $(SRCS:.c=.o)

OBJSBONUS	= $(SRCSBONUS:.c=.o)

INCLUDES	= -I$(HEADER)

NAME		= libft.a

BONUS		= bonus

CC			= clang
LIB			= ar -rcs
RM			= rm -f

CFLAGS		= -Wall -Werror -Wextra

.c.o:	
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(INCLUDES)

$(NAME):	$(OBJS)
			$(LIB) $(NAME) $(OBJS)

$(BONUS):	$(OBJS) $(OBJSBONUS)
			$(LIB) $(NAME) $(OBJS) $(OBJSBONUS)

all:		$(NAME)

clean: 		
			$(RM) $(OBJS) $(OBJSBONUS)

fclean:		clean
			$(RM) $(NAME) $(BONUS)

re:			fclean all

.PHONY:		all clean fclean re bonus
