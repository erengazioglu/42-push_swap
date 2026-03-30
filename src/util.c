/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 18:13:06 by egaziogl          #+#    #+#             */
/*   Updated: 2026/03/30 18:18:05 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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