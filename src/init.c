/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 00:24:43 by egaziogl          #+#    #+#             */
/*   Updated: 2026/03/30 00:53:43 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// (checked on main)

static void	parse_many(char *input, t_state *state);

static void	parse_one(char *input, t_state *state)
{
	char	**list;
	
	list = ft_split(input, ' ');
	if (!list)
		crash(state, ERR_INIT);
}

static void	parse(int argc, char **argv)
{
	// this is where you check and decide which parse to use (above)
	if (argc != 2)
		crash(NULL, ERR_ARGS);
}

t_state	*init(int argc, char **argv)
{
	t_state	*state;


	state = ft_calloc(1, sizeof(t_state));
	if (!state)
		crash(NULL, ERR_INIT);
	state->a = ft_calloc(1, sizeof(t_stack));
	state->b = ft_calloc(1, sizeof(t_stack));
	if (!state->a || !state->b)
		crash(state, ERR_INIT);
	return state;
}
