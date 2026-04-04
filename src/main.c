/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 23:45:58 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/04 14:17:44 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_stack(t_stack *stack)
{
	t_node	*curr;
	int		i;

	if (!stack->bottom)
		return ;
	i = 0;
	curr = stack->bottom;
	while (i++ < stack->count - 1)
	{
		ft_printf("%d ", curr->val);
		curr = curr->prev;
	}
	ft_printf("%d", curr->val);
}

// prints the two stacks
void	ps(t_state *state, bool final)
{
	if (final)
	{
		ft_printf("%sa: ", GRN);
		print_stack(state->a);
		ft_printf(" | b: ");
		print_stack(state->b);
		ft_printf("%s\n", RST);
	}
	else
	{
		write(1, "---\na: ", 7);
		print_stack(state->a);
		write(1, "\nb: ", 3);
		print_stack(state->b);
		write(1, "\n---\n", 4);
	}
}

int	main(int argc, char **argv)
{
	t_state	*state;

	state = init(argc, argv);
	if (state->a->count <= 5)
		sort_a(state);
	else
		solve(state);
	free_stack(state->a);
	free_stack(state->b);
	free(state);
	return (0);
}
