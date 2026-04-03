/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 14:31:20 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/03 13:56:39 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	add_top(t_stack *stack, int val)
{
	t_node	*node;

	node = ft_calloc(1, sizeof(t_node));
	if (!node)
		return (false);
	node->val = val;
	if ((!stack->bottom && !stack->top) || stack->count == 0)
		stack->bottom = node;
	else
	{
		stack->top->prev = node;
		node->next = stack->top;
	}
	stack->top = node;
	stack->count++;
	set_minmax(stack, val);
	return (true);
}

bool	add_bottom(t_stack *stack, int val)
{
	t_node	*node;

	node = ft_calloc(1, sizeof(t_node));
	if (!node)
		return (false);
	node->val = val;
	if ((!stack->bottom && !stack->top) || stack->count == 0)
		stack->top = node;
	else
	{
		stack->bottom->next = node;
		node->prev = stack->bottom;
	}
	stack->bottom = node;
	stack->count++;
	set_minmax(stack, val);
	return (true);
}

t_node	*pop(t_stack *stack, bool reverse)
{
	t_node *node;

	if (!stack->count)
		return (NULL);
	if (stack->count == 1)
		node = stack->bottom;
	else if (reverse)
	{
		node = stack->bottom;
		stack->bottom = stack->bottom->prev;
	}
	else
	{
		node = stack->top;
		stack->top = stack->top->next;
	}
	stack->count--;
	refresh_ends(stack);
	if (node->val == stack->max)
		find_max(stack);
	if (node->val == stack->min)
		find_min(stack);
	return (node->prev = NULL, node->next = NULL, node);
}

void	push(t_stack *stack, t_node *node, bool reverse)
{
	if (!stack->count)
	{
		stack->bottom = node;
		stack->top = node;
	}
	else if (reverse)
	{
		node->prev = stack->bottom;
		stack->bottom->next = node;
		stack->bottom = node;
	}
	else
	{
		node->next = stack->top;
		stack->top->prev = node;
		stack->top = node;
	}
	stack->count++;
	set_minmax(stack, node->val);
}