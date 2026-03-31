/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 20:50:30 by egaziogl          #+#    #+#             */
/*   Updated: 2026/03/31 21:29:01 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	check_order(t_stack *stack, bool reverse)
{
	t_node	*curr;

	curr = stack->top;
	if (!curr)
		return (true);
	while (curr->next)
	{
		if (reverse)
		{
			if (curr->value < curr->next->value
				&& curr->value != stack->min)
				return (false);
		}
		else
		{
			if (curr->value > curr->next->value
				&& curr->value != stack->max)
				return (false);
		}
		curr = curr->next;
	}
	return (true);
}
