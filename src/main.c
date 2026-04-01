/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 23:45:58 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/01 17:29:39 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_state	*state;
	int	dist;

	state = init(argc, argv);
	fill_random(state->a, 100);
	empty_stack(state->b);
	state->moves = 0;
	begin(state);
	print_stacks(state);


	while (state->a->count)
	{
		dist = distance_from_top(state->b, state->a->top->val);
		while (dist--)
			do_rotate(state, false, true);
		do_push(state, true);
		print_stacks(state);
	}
	while (state->b->top->val != state->b->max)
		do_rotate(state, false, true);
	print_stacks(state);
	while (state->b->count)
		do_push(state, false);
	print_stacks(state);
	ft_printf("total moves: %d\n", state->moves);
	return (0);
}
