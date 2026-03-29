/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 23:39:15 by egaziogl          #+#    #+#             */
/*   Updated: 2026/03/30 00:48:06 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"

typedef enum e_err {
	ERR_ARGS,
	ERR_INIT
}	t_err;

typedef	struct s_stack {
	t_list	*top;
	t_list	*bottom;
}	t_stack;

typedef	struct s_state
{
	t_stack	*a;
	t_stack	*b;
	t_err	err;
}	t_state;

// crash.c
void	crash(t_state *state, t_err err);

#endif