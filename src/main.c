/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 23:45:58 by egaziogl          #+#    #+#             */
/*   Updated: 2026/03/30 00:21:42 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_state	*init(int argc, char **argv)
{
	t_state	*state;

	if (argc != 2)
		crash(NULL);
	state = ft_calloc(1, sizeof(t_state));
	if (!state)
		crash(NULL);
	state->a = ft_calloc(1, sizeof(t_stack));
	state->b = ft_calloc(1, sizeof(t_stack));
	if (!state->a || !state->b)
	{
		state->err = ERR_INIT;
		crash(state);
	}
	return state;
}

int	main(int argc, char **argv)
{
	t_state	*state;

	state = init(argc, argv);
}