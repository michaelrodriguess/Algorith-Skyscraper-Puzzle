SRCS			= ./main.c \
				  ./src/algorithm.c \
				  ./src/validation.c \
				  ./src/utils.c \
				  ./src/ft_bzero.c \
				  ./src/ft_calloc.c \
				  ./src/ft_split.c \
				  ./src/ft_substr.c

NAME			= rush-01

OBJS			= $(SRCS:.c=.o)
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g -I includes/ 


$(NAME):	$(SRCS) $(OBJS)
		$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

clean:
		$(RM) $(OBJS)

fclean:	clean
	   	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
