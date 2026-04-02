/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 10:12:36 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/02 17:46:16 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// checks from above.
// from below is simply (stack->count - cost) % stack->count.
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

// TODO
void	seek_cheaper_bottom(t_state *state, t_ins *ins)
{
	(void) state;
	(void) ins;
}





// int	find_cheapest(t_state *state)
// {
// 	int		cost[2];
// 	t_node	*node;
// 	int		index;
// 	bool	reverse;

// 	node = state->a->top;
// 	cost[0] = check_insertion_cost(state->b, node->val);
// 	cost[1] = (state->b->count - cost[0]) % state->b->count;
// 	index = seek_cheaper(state, ft_min(cost[0], cost[1]));
// 	// ft_printf("%s%d:\ttop %d, bottom %d%s\n", YEL, node->val, dist[0], dist[1], RST);
// 	// index = seek_cheaper(state, dist);




// 	// if (dist[0] < dist[1])
// 	// 	index = seek_cheaper_top(state, dist);
// 	// else
// 	// 	index = seek_cheaper_bottom(state, dist) * -1;
// 	if (index)
// 	{
// 		node = stack_get(state->a, index);
// 		ft_printf(
// 			"%s%d:\ttop %d, bottom %d%s\n", YEL, 
// 			node->val, 
// 			distance_from_top(state->b, node->val), 
// 			distance_from_bottom(state->b, node->val), RST
// 		);
// 	}
// 	return (index);
// }
