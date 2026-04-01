/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 20:50:30 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/01 14:26:55 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	distance_from_top(t_stack *target, int val)
{
	t_node	*curr;
	t_node	*prev;
	int		dist;

	if (target->count < 3)
		return (0);
	dist = 0;
	curr = target->top;
	prev = target->bottom;
	while (curr)
	{
		// if (val < )
		if (val > curr->val && (prev->val > val || prev->val == target->min))
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
