/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 18:13:06 by egaziogl          #+#    #+#             */
/*   Updated: 2026/04/03 20:20:51 by egaziogl         ###   ########.fr       */
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

bool	ft_isnum(char *s)
{
	if (*s == '-')
		s++;
	if (!*s)
		return (false);
	while (*s && ft_isdigit(*s))
		s++;
	if (*s)
		return (false);
	return (true);
}
