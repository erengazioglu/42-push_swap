/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 11:16:09 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/03 12:05:35 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	begin(t_state *state)
{
	int	i;
	
	i = 0;
	while (i++ < 3)
		do_push(state, false);
	if (!check_order(state->b, true))
		do_swap(state, false, true);
}

// TODO
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
	// (void) state;
	// (void) ins;
	// return ;
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
	print_insertion(&ins);
	insert(state, ins);
	print_stacks(state);
	ft_printf("\n");
}
