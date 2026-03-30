/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 17:32:36 by egaziogl          #+#    #+#             */
/*   Updated: 2026/03/30 21:49:42 by egaziogl         ###   ########.fr       */
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
