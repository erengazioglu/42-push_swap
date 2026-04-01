/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 23:45:58 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/01 14:23:58 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_state	*state;
	int	dist;

	state = init(argc, argv);
	print_stacks(state);
	dist = distance_from_top(state->b, state->a->top->val);
	ft_printf("dist from top: %d\n", dist);
	return (0);
	


	// for (int i = 0; i < 3; i++)
	// 	push(state->b, pop(state->a, false), false);

	// test_satoi(state);
}