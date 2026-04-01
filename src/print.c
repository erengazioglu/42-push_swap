/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 21:49:05 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/01 14:23:59 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_stack(t_stack *stack)
{
	t_node	*curr;
	int		i;

	if (!stack->bottom)
	{
		ft_printf("\n");
		return ;
	}
	i = 0;
	curr = stack->bottom;
	while (i++ < stack->count - 1)
	{
		ft_printf("%d ", curr->val);
		curr = curr->prev;
	}
	ft_printf("%d\n", curr->val);
}

void	print_stacks(t_state *state)
{
	write(1, "a: ", 3);
	print_stack(state->a);
	write(1, "b: ", 3);
	print_stack(state->b);
}
