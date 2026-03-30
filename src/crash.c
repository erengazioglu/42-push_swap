/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 23:59:24 by egaziogl          #+#    #+#             */
/*   Updated: 2026/03/30 21:27:32 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	crash(t_state *state, t_err err)
{
	(void) state;
	
	ft_printf("err: %d\n", err);
	exit(1);
}
