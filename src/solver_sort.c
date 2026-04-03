/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 12:00:43 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/03 23:34:50 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static bool	swap_condition(t_stack *stack, t_node *n1, t_node *n2)
{
	return (
		n1->val > n2->val && !(n1->val == stack->max && n2->val == stack->min)
	);
}

void	rewind_a(t_state *state)
{
	if (!state->a->count)
		return ;
	if (seek(state->a->top, state->a->min, false) > (state->a->count / 2))
	{
		while (state->a->top->val != state->a->min)
			do_rotate_reverse(state, true, false);
	}
	else
	{
		while (state->a->top->val != state->a->min)
			do_rotate(state, true, false);
	}
}

// ascending sort for a only, you don't need this for b
void	sort_a(t_state *state)
{
	t_node	*curr;

	if (state->a->count < 3)
		return ;
	if (state->a->count == 3)
	{
		do_swap(state, true, false);
		return ;
	}
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
	}
}

void	transfer(t_state *state)
{
	while (state->b->count && state->a->min > state->b->max)
		do_push(state, true);
	while (state->b->count)
	{
		if (state->a->min < state->b->max)
		{
			while (state->a->bottom->val > state->b->top->val)
				do_rotate_reverse(state, true, false);
			do_push(state, true);
		}
		else if (
			state->a->bottom->prev->val == state->a->max
			&& state->a->bottom->val > state->b->top->val
		)
			do_rotate_reverse(state, true, false);
		else
			do_push(state, true);
	}
}
