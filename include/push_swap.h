/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 23:39:15 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/01 18:35:21 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"

typedef enum e_err {
	NOERR,
	ERR_INIT,
	ERR_ARGC,
	ERR_ARGV,
	ERR_DUP,
	ERR_STACK_EMPTY
}	t_err;

typedef struct s_node {
	int				val;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack {
	t_node	*top;
	t_node	*bottom;
	int		count;
	int		min;
	int		max;
}	t_stack;

typedef	struct s_state
{
	int		moves;
	t_stack	*a;
	t_stack	*b;
	t_err	err;
}	t_state;

// crash.c
void	crash(t_state *state, t_err err);

// init.c
t_state	*init(int argc, char **argv);

// stack_modify.c
void	transfer(t_stack *from, t_stack *to, bool reverse);
void	swap(t_stack *stack);
void	rotate(t_stack *stack, bool reverse);

// stack_add.c
bool	add_top(t_stack *stack, int val);
bool	add_bottom(t_stack *stack, int val);
t_node	*pop(t_stack *stack, bool reverse);
void	push(t_stack *stack, t_node *node, bool reverse);

// stack_find.c
int		find_down(t_node *node, int val);
int		find_up(t_node *node, int val);
int		find_min(t_stack *stack);
int		find_max(t_stack *stack);

// stack_util.c
void	refresh_ends(t_stack *stack);
void	refresh_minmax(t_stack *stack);
void	set_minmax(t_stack *stack, int val);

// stack_random.c
void	fill_random(t_stack *stack, int size);
void	empty_stack(t_stack *stack);

// util.c
bool	ft_isnum(char *s);

// print.c
void	print_stack(t_stack *stack);
void	print_stacks(t_state *state);

// ft_satoi.c
int		ft_satoi(t_state *state, const char *str);

// tests.c
void	test_satoi(t_state *state);
void	test_stack_ops(t_state *state);
void	test_pop_push(t_state *state);

// check.c
int		distance_from_top(t_stack *target, int val);
int		distance_from_bottom(t_stack *target, int val);
bool	check_order(t_stack *stack, bool reverse);

// do.c
void	do_swap(t_state *state, bool a, bool b);
void	do_rotate(t_state *state, bool a, bool b);
void	do_rotate_reverse(t_state *state, bool a, bool b);
void	do_push(t_state *state, bool b);

// solver.c
void	begin(t_state *state);


#endif