/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 22:46:29 by egaziogl          #+#    #+#             */
/*   Updated: 2026/03/31 14:59:24 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	test_pop_push(t_state *state)
{
	t_node	*node;

	node = pop(state->a, false);
	if (!node)
		return (0);
	ft_printf("popped %d from a\n", node->value);
	print_stacks(state);
	push(state->b, node, false);
	ft_printf("pushed %d to b\n", node->value);
	print_stacks(state);
}
