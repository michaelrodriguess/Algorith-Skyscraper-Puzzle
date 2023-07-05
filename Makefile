SRCS			= ./main.c \
				  ./src/algorithm.c \
				  ./src/validation.c \
				  ./src/utils.c 

NAME			= rush-01

OBJS			= $(SRCS:.c=.o)
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I includes/ 


$(NAME):	$(SRCS) $(OBJS)
		$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

clean:
		$(RM) $(OBJS)

fclean:	clean
	   	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
