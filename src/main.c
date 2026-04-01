/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 23:45:58 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/01 18:43:06 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "time.h"

void	sort_and_insert(t_state *state)
{
	int	dist[2];

	dist[0] = distance_from_top(state->b, state->a->top->val);
	dist[1] = distance_from_bottom(state->b, state->a->top->val);
	if (dist[0] < dist[1])
	{
		while (dist[1]--)
			do_rotate(state, false, true);
		do_push(state, true);
	}
	else
	{
		while (dist[0]--)
			do_rotate_reverse(state, false, true);
		do_push(state, true);
	}
	print_stacks(state);
}

int	main(int argc, char **argv)
{
	t_state	*state;

	state = init(argc, argv);
	srand(time(NULL));
	fill_random(state->a, 500);
	empty_stack(state->b);
	state->moves = 0;
	begin(state);
	print_stacks(state);
	while (state->a->count)
		sort_and_insert(state);
	while (state->b->top->val != state->b->max)
		do_rotate(state, false, true);
	print_stacks(state);
	while (state->b->count)
		do_push(state, false);
	print_stacks(state);
	ft_printf("total moves: %d\n", state->moves);
	return (0);
}
