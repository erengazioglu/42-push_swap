/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 12:00:43 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/03 12:58:58 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static bool	swap_condition(t_stack *stack, t_node *n1, t_node *n2)
{
	return (
		n1->val > n2->val && !(n1->val == stack->max && n2->val == stack->min)
	);
}

// ascending sort for a only, you don't need this for b
void	sort_in_place(t_state *state)
{
	t_node	*curr;

	while (!check_order(state->a, false))
	{
		curr = state->a->top;
		while (!swap_condition(state->a, curr, curr->next))
		{
			do_rotate_reverse(state, true, false);
			curr = curr->prev;
		}
		do_swap(state, true, false);
		while (swap_condition(state->a, curr, curr->next))
		{
			do_rotate(state, true, false);
			do_swap(state, true, false);
		}
		check_order(state->a, false);
	}
}