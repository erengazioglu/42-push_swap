/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 11:16:09 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/02 11:01:50 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	begin(t_state *state)
{
	int	i;
	
	i = 0;
	while (i++ < 3)
		do_push(state, true);
	if (!check_order(state->b, true))
		do_swap(state, false, true);
}

void	sort_and_insert(t_state *state, int index)
{
	int	dist[2];
	(void) index; // use it for pre-rotate

	dist[0] = distance_from_top(state->b, state->a->top->val);
	dist[1] = distance_from_bottom(state->b, state->a->top->val);
	if (dist[0] < dist[1])
	{
		while (dist[1]--)
			do_rotate_reverse(state, false, true);
		do_push(state, true);
	}
	else
	{
		while (dist[0]--)
			do_rotate(state, false, true);
		do_push(state, true);
	}
	print_stacks(state);
}
