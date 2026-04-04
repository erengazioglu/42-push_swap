/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 23:45:58 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/04 11:08:26 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_state	*state;

	state = init(argc, argv);
	if (!prepare(state))
		return (0);
	while (state->a->count > 5 && !check_order(state->a, false))
		sort_and_insert(state);
	sort_a(state);
	rewind_a(state);
	rewind_b(state);
	transfer(state);
	rewind_a(state);
	free_stack(state->a);
	free_stack(state->b);
	free(state);
	return (0);
}
