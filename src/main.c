/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 23:45:58 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/01 15:06:36 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_state	*state;
	int	dist;

	state = init(argc, argv);
	print_stacks(state);
	while (state->a->count)
	{
		dist = distance_from_top(state->b, state->a->top->val);
		while (dist--)
			do_rotate(state, false, true);
		do_push(state, true);
		print_stacks(state);
	}	
	return (0);
}
