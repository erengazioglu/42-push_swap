CC		= cc
NAME	= run
CFLAGS	= -Wall -Werror -Wextra -g
INCLUDE = include/push_swap


SRC			= $(filter-out ../src/main.c, $(sort $(wildcard ../src/*.c)))
SRC_TEST	= \
			main.c \
			random.c \
			print.c

$(NAME)	: $(SRC) $(SRC_TEST)
	$(CC) $(CFLAGS) $(SRC) $(SRC_TEST) ../libft/libft.a -o $(NAME)