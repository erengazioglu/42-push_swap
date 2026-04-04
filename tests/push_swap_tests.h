/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tests.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 21:34:43 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/04 16:38:09 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_TESTS_H
# define PUSH_SWAP_TESTS_H

# include "../include/push_swap.h"
# include <stdio.h>
# include <time.h>

void	randomize(t_state *state, int count, long int seed);
void	print_insertion(t_ins *ins);
void	print_stack(t_stack *stack);
void	ps(t_state *state, bool final);

#endif