/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 10:12:36 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/03 20:13:43 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_cost(t_stack *target, int val)
{
	t_node	*curr;
	t_node	*prev;
	int		cost;

	if (target->count < 3)
		return (0);
	if (val > target->max)
		return (seek(target->top, target->max, false));
	if (val < target->min)
		return (seek(target->top, target->min, false) + 1);
	curr = target->top;
	prev = target->bottom;
	cost = 0;
	while (curr)
	{
		if (val > curr->val && val < prev->val)
			return (cost);
		curr = curr->next;
		if (curr)
			prev = curr->prev;
		cost++;
	}
	return (-1);
}

void	seek_cheaper_top(t_state *state, t_ins *ins)
{
	t_node	*node;
	int		i;
	int		cost;

	if (state->a->count < 3)
		return ;
	node = state->a->top->next;
	i = 1;
	while (i < ins->cost && node)
	{
		cost = check_cost(state->b, node->val);
		if (cost < ins->cost + i)
		{
			ins->cost = cost;
			ins->idx = i;
			ins->reverse = false;
		}
		i++;
		node = node->next;
	}
}

void	seek_cheaper_bottom(t_state *state, t_ins *ins)
{
	t_node	*node;
	int		i;
	int		cost;

	if (state->a->count < 3)
		return ;
	node = state->a->bottom;
	i = 1;
	while (i < ins->cost && node)
	{
		cost = check_cost(state->b, node->val);
		cost = (state->b->count - cost) % state->b->count;
		if (cost < ins->cost + i)
		{
			ins->cost = cost;
			ins->idx = i;
			ins->reverse = true;
		}
		i++;
		node = node->prev;
	}
}
