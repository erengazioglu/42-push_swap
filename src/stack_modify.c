/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_modify.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 17:32:36 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/03 14:19:26 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


void	rotate(t_stack *stack, bool reverse)
{
	t_node	*node;

	if (stack->count < 2)
		return ;
	if (reverse)
	{
		node = stack->bottom;
		stack->bottom = node->prev;
		stack->top->prev = node;
		node->next = stack->top;
		stack->top = node;
	}
	else
	{
		node = stack->top;
		stack->top = node->next;
		stack->bottom->next = node;
		node->prev = stack->bottom;
		stack->bottom = node;
	}
	refresh_ends(stack);
}

void	swap(t_stack *stack)
{
	t_node *node;

	if (stack->count < 2)
		return ;
	node = stack->top->next;
	node->next->prev = stack->top;
	node->prev->next = node->next;
	node->next = stack->top;
	node->next->prev = node;
	stack->top = node;
	node->prev = NULL;
}


