/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 20:50:30 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/04 16:54:43 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static bool	check_order_descending(t_stack *stack)
{
	t_node	*curr;

	curr = stack->top;
	if (!curr || !curr->next)
		return (true);
	while (curr->next)
	{
		if (
			curr->val < curr->next->val
			&& !(curr->val == stack->min && curr->next->val == stack->max)
		)
			return (false);
		curr = curr->next;
	}
	return (
		curr->val > stack->top->val
		|| (curr->val < stack->top->val && curr->val == stack->min)
	);
}

static bool	check_order_ascending(t_stack *stack)
{
	t_node	*curr;

	curr = stack->top;
	if (!curr || !curr->next)
		return (true);
	while (curr->next)
	{
		if (
			curr->val > curr->next->val
			&& !(curr->val == stack->max && curr->next->val == stack->min)
		)
			return (false);
		curr = curr->next;
	}
	return (
		curr->val < stack->top->val
		|| (curr->val > stack->top->val && curr->val == stack->max)
	);
}

bool	check_order(t_stack *stack, bool descending)
{
	if (descending)
		return (check_order_descending(stack));
	return (check_order_ascending(stack));
}
