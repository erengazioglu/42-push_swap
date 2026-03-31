/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 17:32:36 by egaziogl          #+#    #+#             */
/*   Updated: 2026/03/31 17:29:10 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// int	find_up(t_node *node, int val)
// {
// 	int	i;

// 	if (!node->next)
// 		return (0);
// 	i = 1;
// 	node = node->next;
// 	while (node)
// 	{
// 		if (node->value == val)
// 			return (i);
// 		node = node->next;
// 		i++;
// 	}
// }

int	find_down(t_node *node, int val)
{
	int	i;

	if (!node->next)
		return (0);
	i = 1;
	node = node->next;
	while (node)
	{
		if (node->value == val)
			return (i);
		node = node->next;
		i++;
	}
	return (0);
}

bool	add_top(t_stack *stack, int val)
{
	t_node	*node;

	node = ft_calloc(1, sizeof(t_node));
	if (!node)
		return (false);
	node->value = val;
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

bool	add_bottom(t_stack *stack, int val)
{
	t_node	*node;

	node = ft_calloc(1, sizeof(t_node));
	if (!node)
		return (false);
	node->value = val;
	if ((!stack->bottom && !stack->top) || stack->count == 0)
		stack->top = node;
	else
	{
		stack->bottom->next = node;
		node->prev = stack->bottom;
	}
	stack->bottom = node;
	stack->count++;
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
