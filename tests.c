/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaziogl <egaziogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 22:46:29 by egaziogl          #+#    #+#             */
/*   Updated: 2026/03/24 22:49:55 by egaziogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	random(int min, int max)
{
	return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

int	main(void)
{
	int	a[12];
	int	b[12];

	for (int i = 0; i < 12; i++)
		a[i] = random(0, 99);
}