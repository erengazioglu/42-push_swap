/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 23:45:58 by egaziogl          #+#    #+#             */
/*   Updated: 2026/03/31 17:14:05 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_state	*state;

	state = init(argc, argv);
	print_stacks(state);
	transfer(state->a, state->b, false);
	ft_printf("transferred from a to b\n");
	print_stacks(state);
	rotate(state->b, false);
	rotate(state->b, false);
	ft_printf("rotated b twice\n");
	print_stacks(state);
	rotate(state->b, true);
	ft_printf("reverse rotate b once\n");
	print_stacks(state);
	swap(state->b);
	ft_printf("swap b once\n");
	print_stacks(state);
}