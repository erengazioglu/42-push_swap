/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_satoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 17:47:30 by egaziogl          #+#    #+#             */
/*   Updated: 2026/03/31 18:27:16 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	init_satoi(const char **str)
{
	if (**str == '-')
	{
		(*str)++;
		return (-1);
	}
	return (1);
}

// strict atoi:
// won't skip leading whitespace
// won't accept trailing invalid characters
// won't accept '+' at the beginning
// will accept only 1 optional '-'
int	ft_satoi(t_state *state, const char *str)
{
	int	acc;
	int	sign;
	int	digit;

	if (!ft_strncmp(str, "-2147483648", 11))
		return (-2147483648);
	if (!(*str))
		crash(state, ERR_ARGV);
	sign = init_satoi(&str);
	if (!(*str))
		crash(state, ERR_ARGV);
	acc = 0;
	while (ft_isdigit(*str))
	{
		digit = *(str++) - '0';
		if (acc > (2147483647 - digit) / 10)
			crash(state, ERR_ARGV);
		acc = acc * 10 + digit;
	}
	if (*str)
		crash(state, ERR_ARGV);
	return (sign * acc);
}
