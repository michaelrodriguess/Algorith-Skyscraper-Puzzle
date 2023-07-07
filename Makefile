SRCS			= ./main.c \
				  ./src/algorithm.c \
				  ./src/validations.c \
				  ./src/utils1.c \
				  ./src/utils2.c \
				  ./src/ft_split.c \
				  ./src/clear_memory.c 

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
