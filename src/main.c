/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 23:45:58 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/03 20:00:20 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_state	*state;

	state = init(argc, argv);
	print_stacks(state);
	while (state->a->count > 5 && !check_order(state->a, false))
		sort_and_insert(state);
	sort_a(state);
	rewind_a(state);
	rewind_b(state);
	transfer(state);
	rewind_a(state);
	ft_printf("%sfinished in %d moves%s\n", GRN, state->moves, RST);
	print_stacks(state);
	return (0);
}
