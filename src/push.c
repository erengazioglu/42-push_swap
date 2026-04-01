/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 12:28:21 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/01 11:15:51 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_a(t_state *state)
{
	t_node	*node;
	t_stack	*stack;

	node = pop_top(state->b);
	stack = state->a;
	if (!node)
		crash(state, ERR_STACK_EMPTY);
	if (stack->count == 0)
		stack->bottom = node;
	else
	{
		node->next = stack->top;
		stack->top->prev = node;
	}
	stack->top = node;
	stack->count++;
}

void	push_b(t_state *state)
{
	
}