CC		= cc
NAME	= push_swap
CFLAGS	= -Wall -Werror -Wextra -g
LIBS	= libft/libft.a
INCLUDE = include/push_swap

SRC		= \
		main.c \
		stack_add.c \
		stack_find.c \
		stack_modify.c \
		stack_util.c \
		stack_check.c \
		util.c \
		init.c \
		crash.c \
		print.c \
		do.c \
		solver.c \
		solver_cost.c \
		solver_sort.c

OBJ		:= $(SRC:%.c=obj/%.o)

all		: $(NAME)

$(NAME)	: $(OBJ) $(LIBS)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $@
$(OBJ): $(SRC:%.c=src/%.c) libft/libft.a
	@mkdir -p obj
	$(CC) $(CFLAGS) -c $(@:obj/%.o=src/%.c) -o $@

libft/libft.a:
	make -C libft
clean	: 
	rm -rf obj
fclean	: clean
	rm -f $(NAME) $(BONUS)
	rm -f libft/libft.a
re: fclean all
