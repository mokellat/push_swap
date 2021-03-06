/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 13:37:03 by mokellat          #+#    #+#             */
/*   Updated: 2021/06/23 13:16:46 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*rra(int *stack_a, int size)
{
	int	temp;
	int	i;

	temp = stack_a[size - 1];
	i = size - 1 ;
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = temp;
	if (DISPLAY)
		write(1, "rra\n", 4);
	return (stack_a);
}
