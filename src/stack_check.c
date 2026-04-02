/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 20:50:30 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/02 12:40:17 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	distance_from_bottom(t_stack *target, int val)
{
	t_node	*curr;
	t_node	*next;
	int		dist;

	if (target->count < 3)
		return (0);
	if (val > target->max)
		return (seek(target->bottom, target->max, true) + 1);
	if (val < target->min)
		return (seek(target->bottom, target->min, true));
	dist = 0;
	curr = target->bottom;
	next = target->top;
	while (curr)
	{
		if (val < curr->val && val > next->val)
			return (dist);
		curr = curr->prev;
		if (curr)
			next = curr->next;
		dist++;
	}
	return (-1);
}


int	distance_from_top(t_stack *target, int val)
{
	t_node	*curr;
	t_node	*prev;
	int		dist;

	if (target->count < 3)
		return (0);
	if (val > target->max)
		return (seek(target->top, target->max, false));
	if (val < target->min)
		return (seek(target->top, target->min, false) + 1);
	dist = 0;
	curr = target->top;
	prev = target->bottom;
	while (curr)
	{
		if (val > curr->val && val < prev->val)
			return (dist);
		curr = curr->next;
		if (curr)
			prev = curr->prev;
		dist++;
	}
	return (-1);
}

// void	check_cost(t_stack *target, t_node *node, int cost[2])
// {
	
// }

bool	check_order(t_stack *stack, bool descending)
{
	t_node	*curr;

	curr = stack->top;
	if (!curr)
		return (true);
	while (curr->next)
	{
		if (descending)
		{
			if (curr->val < curr->next->val
				&& curr->val != stack->min)
				return (false);
		}
		else
		{
			if (curr->val > curr->next->val
				&& curr->val != stack->max)
				return (false);
		}
		curr = curr->next;
	}
	return (true);
}
