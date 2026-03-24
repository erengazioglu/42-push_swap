/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 22:46:29 by egaziogl          #+#    #+#             */
/*   Updated: 2026/03/24 22:58:06 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/include/libft.h"

int	ft_randint(int min, int max)
{
	return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

int	main(void)
{
	int	a[12];
	// int	b[12];

	for (int i = 0; i < 12; i++)
		a[i] = ft_randint(0, 99);
	
	for (int i = 0; i < 12; i++)
		ft_printf("%d ", a[i]);
}