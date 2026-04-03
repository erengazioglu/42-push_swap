/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 14:33:48 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/03 17:34:31 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// CAREFUL: you might lose references to nodes
void	refresh_ends(t_stack *stack)
{
	if (stack->count)
	{
		stack->bottom->next = NULL;
		stack->top->prev = NULL;
	}
	else
	{
		stack->bottom = NULL;
		stack->top = NULL;
	}
}

void	refresh_minmax(t_stack *stack)
{
	if (!stack->count)
	{
		stack->min = 0;
		stack->max = 0;
	}
	else if (stack->count == 1)
	{
		stack->min = stack->top->val;
		stack->max = stack->top->val;
	}
	else
	{
		find_min(stack);
		find_max(stack);
	}
}

void	set_minmax(t_stack *stack, int val)
{
	if (stack->count == 1)
	{
		stack->min = val;
		stack->max = val;
	}
	else
	{
		if (val < stack->min)
			stack->min = val;
		if (val > stack->max)
			stack->max = val;
	}
}

t_node	*stack_get(t_stack *stack, int index)
{
	t_node	*node;
	
	if (index == 0)
		return (stack->top);
	if (index < 0)
	{
		index = (index * -1) - 1;
		if (stack->count <= index)
			return (NULL);
		node = stack->bottom;
		while (index--)
			node = node->prev;
	}
	else
	{
		if (stack->count <= index)
			return (NULL);
		node = stack->top;
		while (index--)
			node = node->next;
	}
	return (node);
}