/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 21:27:50 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/04 11:11:37 by egaziogl         ###   ########.fr       */
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

void	solve(t_state *state)
{
	if (!prepare(state))
		return ;
	ps(state, false);
	while (state->a->count > 5 && !check_order(state->a, false))
		sort_and_insert(state);
	sort_a(state);
	rewind_a(state);
	rewind_b(state);
	// transfer(state);
	// rewind_a(state);
	ft_printf("%sfinished in %d moves%s\n", GRN, state->moves, RST);
	ps(state, true);
}

int	main(void)
{
	t_state		*state;
	long int	seed;
	
	seed = time(NULL);
	state = init_test();
	randomize(state, 100, seed);
	solve(state);
	for (int i = 0; i < 9; i++)
	{
		randomize(state, 100, 0);
		solve(state);
		
	}
	printf("%sseed: %ld%s\n", YEL, seed, RST);
}