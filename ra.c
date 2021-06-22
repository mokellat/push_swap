/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:50:05 by mokellat          #+#    #+#             */
/*   Updated: 2021/06/22 09:14:41 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ra(int *stack_a, int size)
{
	int	temp;
	int	i;

	temp = stack_a[0];
	i = 0;
	while (i < size - 1)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[size - 1] = temp;
	write(1, "ra\n", 3);
	return (stack_a);
}
