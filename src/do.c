/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 11:17:06 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/01 15:10:36 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	do_swap(t_state *state, bool a, bool b)
{
	if (a && b)
	{
		swap(state->a);
		swap(state->b);
		ft_printf("ss\n");
	}
	else if (a)
	{
		swap(state->a);
		ft_printf("sa\n");
	}
	else if (b)
	{
		swap(state->b);
		ft_printf("sb\n");
	}
	state->moves++;
}

void	do_rotate(t_state *state, bool a, bool b)
{
	if (a && b)
	{
		rotate(state->a, false);
		rotate(state->b, false);
		ft_printf("rr\n");
	}
	else if (a)
	{
		rotate(state->a, false);
		ft_printf("ra\n");
	}
	else if (b)
	{
		rotate(state->b, false);
		ft_printf("rb\n");
	}
	state->moves++;
}

void	do_rotate_reverse(t_state *state, bool a, bool b)
{
	if (a && b)
	{
		rotate(state->a, true);
		rotate(state->b, true);
		ft_printf("rr\n");
	}
	else if (a)
	{
		rotate(state->a, true);
		ft_printf("ra\n");
	}
	else if (b)
	{
		rotate(state->b, true);
		ft_printf("rb\n");
	}
	state->moves++;
}

// true pushes to b, false pushes to a
void	do_push(t_state *state, bool b)
{
	if (b)
	{
		push(state->b, pop(state->a, false), false);
		ft_printf("pb\n");
	}
	else
	{
		push(state->a, pop(state->b, false), false);
		ft_printf("pa\n");
	}
	state->moves++;
}