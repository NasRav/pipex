NAME		=	pipex

CC			=	gcc
RM			=	/bin/rm -f
CFLAGS		=	-Wall -Wextra -Werror
INCLUDES	=	includes

SRCS		=	srcs/main.c \
				srcs/exec.c \
				srcs/get_path.c \
				ft_lib/ft_putchar_fd.c \
				ft_lib/ft_putendl_fd.c \
				ft_lib/ft_split.c \
				ft_lib/ft_strchr.c \
				ft_lib/ft_strlcpy.c \
				ft_lib/ft_strlen.c \
				ft_lib/ft_strjoin.c \
				ft_lib/ft_strncmp.c

OBJS		=	$(SRCS:.c=.o)


.c.o :
				$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $(<:.c=.o)


$(NAME) :		$(OBJS)	$(INCLUDES)/pipex.h
				$(CC) -o $(NAME) $(OBJS) -I $(INCLUDES)


all :			$(NAME)

clean :
				$(RM) $(OBJS)

fclean :		clean
				$(RM) $(NAME)

re :			fclean \
				all

.PHONY :		all clean fclean re
