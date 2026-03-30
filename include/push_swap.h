/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 23:39:15 by egaziogl          #+#    #+#             */
/*   Updated: 2026/03/30 21:50:11 by egaziogl         ###   ########.fr       */
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
}	t_err;

typedef struct s_node {
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack {
	t_node	*top;
	t_node	*bottom;
	int		count;
}	t_stack;

typedef	struct s_state
{
	t_stack	*a;
	t_stack	*b;
	t_err	err;
}	t_state;

// crash.c
void	crash(t_state *state, t_err err);

// init.c
t_state	*init(int argc, char **argv);

// stack.c
bool	add_top(t_stack *stack, int val);
bool	add_bottom(t_stack *stack, int val);
int		find_down(t_node *node, int val);

// util.c
bool	ft_isnum(char *s);

// print.c
void	print_stack(t_stack *stack);
void	print_stacks(t_state *state);


#endif