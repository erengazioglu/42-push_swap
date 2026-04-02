/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 23:39:15 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/02 15:01:18 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"

typedef enum e_err
{
	NOERR,
	ERR_INIT,
	ERR_ARGC,
	ERR_ARGV,
	ERR_DUP,
	ERR_STACK_EMPTY
}	t_err;

typedef struct s_node
{
	int				val;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
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

/**
 * @brief	Crashes the program gracefully.
 * 			Cleans up allocated resources & displays
 * 			an appropriate error message.
 * @param state	State object.
 * @param err	Error code (enum).
 * @note	\(crash.c\)
 */
void	crash(t_state *state, t_err err);

/**
 * @brief	Parses program arguments and initializes the state object.
 * 			Crashes accordingly if there's any issue.
 * @param argc	Program arg count.
 * @param argv	Program arg values.
 * @return	Fresh state object.
 * @note	\(init.c\)
 */
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

/**
 * @brief	Seeks the node containing a specific value, 
 * 			starting from a given node.
 * @param node	Node to start seeking from.
 * @param val	Value to look for.
 * @param reverse	true = seek next, false = seek prev.
 * @return	Distance from starting point (or -1 if not found).
 * @note	\(stack_find.c\)
 */
int		seek(t_node *node, int val, bool reverse);
int		find_min(t_stack *stack);
int		find_max(t_stack *stack);

// stack_util.c
void	refresh_ends(t_stack *stack);
void	refresh_minmax(t_stack *stack);
void	set_minmax(t_stack *stack, int val);
/**
 * @brief	Return the node at given index.
 * @param stack	Stack to return the node from.
 * @param index	Target index. If negative, counts from the bottom.
 * @return	Node at target index.
 * @note	\(stack_util.c\)
 */
t_node	*stack_get(t_stack *stack, int index);

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
void	test_find_cheapest(t_state *state);
void	randomize(t_state *state, int count, bool seed);

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
void	sort_and_insert(t_state *state, int index);

/**
 * @brief Returns index of cheapest insertion.
 * @param state	State object.
 * @return	Index of node in A that's cheapest to insert into B.
 * 			Negative values = counting from bottom.
 * @note	\(solver_cheapest.c\)
 */
int		find_cheapest(t_state *state);

#endif