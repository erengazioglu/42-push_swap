/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 11:16:09 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/04 12:20:42 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Starts the sorting by sending the first 3 nodes to B.
 * @param state	State object.
 * @return	If false, the program is already over.
 * @note	\(solver.c\)
 */
bool	prepare(t_state *state)
{
	int	i;

	i = 0;
	if (state->a->count == 2)
	{
		if (state->a->top->val > state->a->bottom->val)
			do_swap(state, true, false);
		return (false);
	}
	if (state->a->count == 3)
	{
		if (!check_order(state->a, false))
			do_swap(state, true, false);
		while (state->a->top->val != state->a->min)
			do_rotate(state, true, false);
		return (false);
	}
	while (i++ < 3 && state->a->count)
		do_push(state, false);
	if (!check_order(state->b, true))
		do_swap(state, false, true);
	return (true);
}

void	insert(t_state *state, t_ins ins)
{
	if (!ins.reverse)
	{
		while (ins.cost > 0 || ins.idx > 0)
			do_rotate(state, ins.idx-- > 0, ins.cost-- > 0);
		do_push(state, false);
		return ;
	}
	else
	{
		while (ins.cost > 0 || ins.idx > 0)
			do_rotate_reverse(state, ins.idx-- > 0, ins.cost-- > 0);
		do_push(state, false);
		return ;
	}
}

void	sort_and_insert(t_state *state)
{
	t_ins	ins;
	int		cost_reverse;

	ins.cost = check_cost(state->b, state->a->top->val);
	ins.idx = 0;
	ins.reverse = false;
	cost_reverse = (state->b->count - ins.cost) % state->b->count;
	if (cost_reverse < ins.cost)
	{
		ins.reverse = true;
		ins.cost = cost_reverse;
	}
	seek_cheaper_top(state, &ins);
	seek_cheaper_bottom(state, &ins);
	insert(state, ins);
}

void	rewind_b(t_state *state)
{
	if (seek(state->b->top, state->b->max, false) > (state->b->count / 2))
	{
		while (state->b->top->val != state->b->max)
			do_rotate_reverse(state, false, true);
	}
	else
	{
		while (state->b->top->val != state->b->max)
			do_rotate(state, false, true);
	}
}

void	solve(t_state *state)
{
	int	i;

	if (!prepare(state))
		return ;
	while (state->a->count > 5 && !check_order(state->a, false))
		sort_and_insert(state);
	sort_a(state);
	rewind_a(state);
	rewind_b(state);
	i = 0;
	while (state->b->count && i++ < 10000)
		transfer(state);
	while (state->a->top->val != state->a->min)
		do_rotate_reverse(state, true, false);
}
