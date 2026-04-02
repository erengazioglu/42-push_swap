/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_random.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:58:23 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/02 14:54:17 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// gives an int between 0 and max (exclusive)
int		rand_max(int max)
{
	return (rand() % max);
}

void	empty_stack(t_stack *stack)
{
	while (stack->count)
		free(pop(stack, false));
	stack->max = 0;
	stack->min = 0;
}

void	fill_random(t_stack *stack, int size)
{
	int	val;
	int	max;

	empty_stack(stack);
	max = size * 5;
	while (size--)
	{
		val = rand_max(max);
		if (stack->count)
		{
			while (seek(stack->top, val, false) != -1)
				val = rand_max(max);
		}
		add_top(stack, val);
	}
}