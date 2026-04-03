/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 14:20:53 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/03 19:55:55 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	seek(t_node *node, int val, bool reverse)
{
	int	i;

	i = 0;
	while (node)
	{
		if (node->val == val)
			return (i);
		if (reverse)
			node = node->prev;
		else
			node = node->next;
		i++;
	}
	return (-1);
}

int	find_min(t_stack *stack)
{
	int		min;
	t_node	*curr;

	if (!stack->count)
		return (stack->min = 0, 0);
	if (stack->count == 1)
		return (stack->min = stack->top->val, stack->top->val);
	curr = stack->top;
	min = curr->val;
	while (curr)
	{
		if (curr->val < min)
			min = curr->val;
		curr = curr->next;
	}
	return (stack->min = min, min);
}

int	find_max(t_stack *stack)
{
	int		max;
	t_node	*curr;

	if (!stack->count)
		return (stack->max = 0, 0);
	if (stack->count == 1)
		return (stack->max = stack->top->val, stack->top->val);
	curr = stack->top;
	max = curr->val;
	while (curr)
	{
		if (curr->val > max)
			max = curr->val;
		curr = curr->next;
	}
	return (stack->max = max, max);
}
