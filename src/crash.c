/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 23:59:24 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/03 20:26:06 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*temp;

	if (!stack)
		return ;
	node = stack->top;
	while (node)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
	free(stack);
}

void	crash(t_state *state, t_err err)
{
	(void) state;
	
	free_stack(state->a);
	free_stack(state->b);
	free(state);
	ft_printf("err: %d\n", err);
	exit(1);
}
