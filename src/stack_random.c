/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_random.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:58:23 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/01 18:41:32 by egaziogl         ###   ########.fr       */
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
	int		val;

	empty_stack(stack);
	while (size--)
	{
		val = rand_max(1000);
		if (stack->count)
		{
			while (stack->top->val == val || find_down(stack->top, val))
				val = rand_max(1000);
		}
		add_top(stack, val);
	}
}