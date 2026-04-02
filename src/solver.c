/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 11:16:09 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/02 17:26:30 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	begin(t_state *state)
{
	int	i;
	
	i = 0;
	while (i++ < 3)
		do_push(state, true);
	if (!check_order(state->b, true))
		do_swap(state, false, true);
}

// TODO
void	insert(t_state *state, t_ins ins)
{
	(void) state;
	(void) ins;
	return ;
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
	print_insertion(&ins);
	// seek_cheaper_bottom(state, &ins);


	// if (dist[0] < dist[1])
	// {
	// 	while (dist[1]--)
	// 		do_rotate_reverse(state, false, true);
	// 	do_push(state, true);
	// }
	// else
	// {
	// 	while (dist[0]--)
	// 		do_rotate(state, false, true);
	// 	do_push(state, true);
	// }
	// print_stacks(state);
}
