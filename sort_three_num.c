/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:05:59 by mokellat          #+#    #+#             */
/*   Updated: 2021/06/13 16:56:07 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_numbers(int *stack_a, int *size_a)
{
	int	i;

	i = 0;
	if (stack_a[i] > stack_a[i + 1] && stack_a[i] < stack_a[i + 2])
		sa(stack_a);
	else if (stack_a[i] > stack_a[i + 1] && stack_a[i] > stack_a[i + 2]
		&& stack_a[i + 1] > stack_a[i + 2])
	{
		sa(stack_a);
		rra(stack_a, *size_a);
	}
	else if (stack_a[i] > stack_a[i + 1] && stack_a[i] > stack_a[i + 2]
		&& stack_a[i + 1] < stack_a[i + 2])
		ra(stack_a, *size_a);
	else if (stack_a[i] < stack_a[i + 1] && stack_a[i] < stack_a[i + 2]
		&& stack_a[i + 1] > stack_a[i + 2])
	{
		sa(stack_a);
		ra(stack_a, *size_a);
	}
	else if (stack_a[i] < stack_a[i + 1] && stack_a[i] > stack_a[i + 2])
		rra(stack_a, *size_a);
}
