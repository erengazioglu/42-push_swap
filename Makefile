CC		= cc
NAME	= push_swap
CFLAGS	= -Wall -Werror -Wextra -g
LIBS	= libft/libft.a
INCLUDE = include/push_swap

SRC		= \
		main.c \
		util.c \
		stack.c \
		init.c \
		crash.c

OBJ		:= $(SRC:%.c=obj/%.o)

all		: $(NAME)

$(NAME)	: $(OBJ) $(LIBS)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $@
$(OBJ): $(SRC:%.c=src/%.c) libft/libft.a # ($(INCLUDE))
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
