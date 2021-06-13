/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 13:45:42 by mokellat          #+#    #+#             */
/*   Updated: 2021/06/13 16:50:05 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*rrb(int *stack_a, int size)
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
	write(1, "rrb\n", 4);
	return (stack_a);
}
