/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_cheapest.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 10:12:36 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/02 15:03:17 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	seek_cheaper_top(t_state *state, int dist[2])
{
	int		i;
	int		cheapest;
	int		new_dist;
	t_node	*node;

	if (state->a->count < 3)
		return (0);
	ft_printf("seek top ");
	cheapest = 0;
	i = 1;
	node = state->a->top->next;
	while (i <= dist[0] && node)
	{
		new_dist = distance_from_top(state->b, node->val) + 1;
		if (new_dist < dist[0])
		{
			cheapest = i;
			dist[0] = new_dist;
		}
		i++;
		node = node->next;
	}
	ft_printf("returning %d\n", cheapest);
	return (cheapest);
}

int	seek_cheaper_bottom(t_state *state, int dist[2])
{
	int		i;
	int		cheapest;
	int		new_dist;
	t_node	*node;

	if (state->a->count < 3)
		return (0);
	cheapest = 0;
	i = 1;
	node = state->a->bottom;
	while (i < dist[0] && node)
	{
		new_dist = distance_from_bottom(state->b, node->val) + 1;
		if (new_dist < dist[0])
		{
			cheapest = i;
			dist[0] = new_dist;
		}
		i++;
		node = node->prev;
	}
	return (cheapest);
}

int	find_cheapest(t_state *state)
{
	int		dist[2];
	t_node	*node;
	int		index;

	node = state->a->top;
	dist[0] = distance_from_top(state->b, node->val);
	dist[1] = distance_from_bottom(state->b, node->val);
	ft_printf("%s%d:\ttop %d, bottom %d%s\n", YEL, node->val, dist[0], dist[1], RST);
	index = 0;
	if (dist[0] < dist[1])
		index = seek_cheaper_top(state, dist);
	else
		index = seek_cheaper_bottom(state, dist) * -1;
	return (index);
}