/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 22:46:29 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/02 13:23:15 by egaziogl         ###   ########.fr       */
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
	// these should work
	ft_printf("%d\n", ft_satoi(state, "1230"));
	ft_printf("%d\n", ft_satoi(state, "0123"));
	ft_printf("%d\n", ft_satoi(state, "-1230"));
	ft_printf("%d\n", ft_satoi(state, "2147483647"));
	ft_printf("%d\n", ft_satoi(state, "-2147483648"));
	// these shouldn't
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

void	test_min_max(t_state *state)
{
	ft_printf("min: %d\n", find_min(state->a));
	ft_printf("max: %d\n", find_max(state->a));
}

void	test_naive_solve(t_state *state)
{
	int	index;
	
	fill_random(state->a, 10);
	empty_stack(state->b);
	state->moves = 0;
	begin(state);
	print_stacks(state);
	index = 0; // replace with cheapest index
	while (state->a->count)
		sort_and_insert(state, index);
	while (state->b->top->val != state->b->max)
		do_rotate(state, false, true);
	print_stacks(state);
	while (state->b->count)
		do_push(state, false);
	print_stacks(state);
	ft_printf("total moves: %d\n", state->moves);
}

void	randomize(t_state *state, int count, bool seed)
{
	if (seed)
		srand(time(NULL));
	fill_random(state->a, count);
	empty_stack(state->b);
	state->moves = 0;
	begin(state);
}

void	test_find_cheapest(t_state *state)
{
	int		index;
	t_node	*node;

	index = find_cheapest(state);
	if (index)
	{
		node = stack_get(state->a, index);
		ft_printf(
			"%s%d:\ttop %d, bottom %d%s\n", YEL, 
			node->val, 
			distance_from_top(state->b, node->val), 
			distance_from_bottom(state->b, node->val), RST
		);
	}
}
