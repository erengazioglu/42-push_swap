/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 00:24:43 by egaziogl          #+#    #+#             */
/*   Updated: 2026/03/31 18:36:52 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static bool	has_duplicates(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	while (node)
	{
		if (find_down(node, node->value))
			return (true);
		node = node->next;
	}
	return (false);
}

static void	parse_many(t_state *state, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_isnum(argv[i]))
			crash(state, ERR_ARGV);
		add_bottom(state->a, ft_satoi(state, argv[i]));
		i++;
	}
}

static void	parse_one(t_state *state, char *input)
{
	char	**list;
	int		i;

	list = ft_split(input, ' ');
	if (!list)
		crash(state, ERR_INIT);
	i = 0;
	while (list[i])
	{
		if (!ft_isnum(list[i]))
		{
			free_list(list);
			crash(state, ERR_ARGV);
		}
		add_bottom(state->a, ft_satoi(state, list[i++]));
	}
	free_list(list);
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
	if (argc == 1)
		crash(state, ERR_ARGC);
	else if (argc == 2)
		parse_one(state, argv[1]);
	else
		parse_many(state, argc, argv);
	if (has_duplicates(state->a))
		crash(state, ERR_DUP);
	return (state);
}
