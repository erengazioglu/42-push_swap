/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 17:32:36 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/01 14:24:05 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"






// CAREFUL: you might lose references to nodes
static void	refresh_ends(t_stack *stack)
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

void	transfer(t_stack *from, t_stack *to, bool reverse)
{
	t_node	*node;

	while (from->count)
	{
		node = pop(from, false);
		push(to, node, reverse);
	}
}

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
	node = stack->top->next;		// 6
	node->next->prev = stack->top;	// 1->prev=8
	node->prev->next = node->next;	// 8->next=1
	node->next = stack->top;
	node->next->prev = node;
	stack->top = node;
	node->prev = NULL;
}

void	refresh_limits(t_stack *stack)
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
		stack->min = find_min(stack);
		stack->max = find_max(stack);
	}
}
