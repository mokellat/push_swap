/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:28:46 by mokellat          #+#    #+#             */
/*   Updated: 2021/06/13 16:47:29 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*rb(int *stack_b, int size)
{
	int	temp;
	int	i;

	temp = stack_b[0];
	i = 0;
	while (i < size - 1)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	stack_b[size - 1] = temp;
	write(1, "rb\n", 3);
	return (stack_b);
}
