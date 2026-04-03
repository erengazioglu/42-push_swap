/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 22:46:29 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/03 14:07:44 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "time.h"

void	test_pop_push(t_state *state)
{
	t_node	*node;

	node = pop(state->a, false);
	if (!node)
		return ;
	ft_printf("popped %d from a\n", node->val);
	print_stacks(state);
	push(state->b, node, false);
	ft_printf("pushed %d to b\n", node->val);
	print_stacks(state);
}

void	test_satoi(t_state *state)
{
	ft_printf("%d\n", ft_satoi(state, "1230"));
	ft_printf("%d\n", ft_satoi(state, "0123"));
	ft_printf("%d\n", ft_satoi(state, "-1230"));
	ft_printf("%d\n", ft_satoi(state, "2147483647"));
	ft_printf("%d\n", ft_satoi(state, "-2147483648"));
	ft_printf("%d\n", ft_satoi(state, "2147483648"));
	ft_printf("%d\n", ft_satoi(state, "-2147483649"));
	ft_printf("%d\n", ft_satoi(state, "--1230"));
	ft_printf("%d\n", ft_satoi(state, "-"));
	ft_printf("%d\n", ft_satoi(state, "+50"));
}

void	test_stack_ops(t_state *state)
{
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

void	randomize(t_state *state, int count, bool seed, bool push3)
{
	if (seed)
		srand(time(NULL));
	fill_random(state->a, count);
	empty_stack(state->b);
	state->moves = 0;
	if (push3)
		begin(state);
}
#include <stdio.h>

void	test_solve(t_state *state)
{
	print_stacks(state);
	if (!check_order(state->b, true))
	{
		ft_printf("not in order\n");
		do_swap(state, false, true);
	}
	while (state->a->count > 3 && !check_order(state->a, false))
		sort_and_insert(state);
	if (!check_order(state->a, false))
		do_swap(state, true, false);
	if (seek(state->b->top, state->b->max, false)
		> (state->b->count / 2))
	{
		while (state->b->top->val != state->b->max)
			do_rotate_reverse(state, false, true);
	}
	else
	{
		while (state->b->top->val != state->b->max)
			do_rotate(state, false, true);
	}
	ft_printf("%sfinished in %d moves%s\n", GRN, state->moves, RST);
	print_stacks(state);
	state->moves = 0;
	printf("%s(seed): %ld%s\n", YEL, time(NULL), RST);
}

void	test_sort_in_place(t_state *state)
{
	print_stacks(state);
	sort_a(state);
	ft_printf("%sfinished in %d moves%s\n", GRN, state->moves, RST);
	print_stacks(state);
	state->moves = 0;
	printf("%s(seed): %ld%s\n", YEL, time(NULL), RST);
}
