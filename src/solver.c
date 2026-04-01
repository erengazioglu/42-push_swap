/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 11:16:09 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/01 13:42:47 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	begin(t_state *state)
{
	int	i;
	
	i = 0;
	while (i++ < 3)
		do_push(state, true);
	if (!check_order(state->b, true))
		do_swap(state, false, true);
}


