/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 21:27:50 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/04 12:09:49 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_tests.h"

t_state	*init_test(void)
{
	t_state	*state;

	state = ft_calloc(1, sizeof(t_state));
	if (!state)
		crash(NULL, ERR_INIT);
	state->a = ft_calloc(1, sizeof(t_stack));
	state->b = ft_calloc(1, sizeof(t_stack));
	if (!state->a || !state->b)
		crash(state, ERR_INIT);
	return (state);
}

int	main(void)
{
	t_state		*state;
	long int	seed;
	
	seed = time(NULL);
	state = init_test();
	randomize(state, 100, seed);
	if (!prepare(state))
	{
		ft_printf("%sfinished in %d moves%s\n", GRN, state->moves, RST);
		ps(state, true);
	}
	solve(state);
	ft_printf("%sfinished in %d moves%s\n", GRN, state->moves, RST);
	ps(state, true);
	for (int i = 0; i < 9; i++)
	{
		randomize(state, 100, 0);
		solve(state);
		ft_printf("%sfinished in %d moves%s\n", GRN, state->moves, RST);
		ps(state, true);
	}
	printf("%sseed: %ld%s\n", YEL, seed, RST);
}
