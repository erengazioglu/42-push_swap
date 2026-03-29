/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 23:59:24 by egaziogl          #+#    #+#             */
/*   Updated: 2026/03/30 00:34:19 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	crash(t_state *state, t_err err)
{
	(void) state;
	(void) err;
	// if (!state)
	// else if (...)
	exit(1);
}