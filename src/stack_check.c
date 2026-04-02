/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 20:50:30 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/03 01:14:27 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
			if (curr->val < curr->next->val && !(
				curr->val == stack->min && curr->next->val == stack->max
			))
				return (false);
		}
		else
		{
			if (curr->val > curr->next->val && !(
				curr->val == stack->max && curr->next->val == stack->min
			))
				return (false);
		}
		curr = curr->next;
	}
	return (true);
}
