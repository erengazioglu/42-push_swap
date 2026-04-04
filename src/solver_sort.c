/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 12:00:43 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/04 16:28:58 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// static bool	swap_condition(t_stack *stack, t_node *n1, t_node *n2)
// {
// 	return (
// 		n1->val > n2->val && !(n1->val == stack->max && n2->val == stack->min)
// 	);
// }

void	rewind_a(t_state *state)
{
	if (state->a->count < 2 || state->a->top->val == state->a->min)
		return ;
	if (state->a->count == 2)
	{
		if (state->a->top->val != state->a->min)
			do_swap(state, true, false);
		return;
	}
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

// ascending sort for a up to 5 elements, you don't need this for b
void	sort_a(t_state *state)
{
	bool	swap_a;
	bool	swap_b;
	int		b_count[2];

	// check_order and rewind account for (count <= 2)
	if (check_order(state->a, false))
	{
		rewind_a(state);
		return ;
	}
	b_count[0] = state->b->count;
	b_count[1] = 0;
	while (state->a->count > 3)
	{
		do_push(state, false);
		b_count[1]++;
	}
	swap_a = !check_order(state->a, false);
	swap_b = b_count[1] == 2
		&& state->b->top->val < state->b->top->next->val;
	do_swap(state, swap_a, swap_b);
	rewind_a(state);
	while (state->b->count > b_count[0])
	{
		if (state->b->top->val > state->a->bottom->val)
			do_push(state, true);
		else if (state->b->top->val < state->a->max
			&& state->b->top->val > state->a->min)
			do_rotate_reverse(state, true, false);
		else
		{
			if (state->a->bottom->val != state->a->max)
				rewind_a(state);
			do_push(state, true);
		}
	}
}

void	transfer(t_state *state)
{
	if (state->b->top->val > state->a->bottom->val)
		do_push(state, true);
	else if (state->b->max > state->a->min)
		do_rotate_reverse(state, true, false);
	else
	{
		rewind_a(state);
		while (state->b->count)
			do_push(state, true);
	}
}

	// while (state->b->count)
	// {
	// 	if (state->a->min < state->b->max)
	// 	{
	// 		while (state->a->bottom->val > state->b->top->val)
	// 			do_rotate_reverse(state, true, false);
	// 		do_push(state, true);
	// 	}
	// 	else if (
	// 		state->a->bottom->prev->val == state->a->max
	// 		&& state->a->bottom->val > state->b->top->val
	// 	)
	// 		do_rotate_reverse(state, true, false);
	// 	else
	// 		do_push(state, true);
	// }