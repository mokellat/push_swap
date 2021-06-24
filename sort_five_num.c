/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 19:21:47 by mokellat          #+#    #+#             */
/*   Updated: 2021/06/24 17:58:55 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	position(int cmpt, int *size_a, int *stack_a)
{
	int	j;

	if (cmpt <= *size_a / 2)
	{
		j = -1;
		while (++j < cmpt)
			ra(stack_a, *size_a);
	}
	else
	{
		j = -1;
		while (++j < *size_a - cmpt)
			rra(stack_a, *size_a);
	}
}

void	sort_five_num(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int	min;
	int	i;
	int	cmpt;
	int	index;

	index = -1;
	while (++index < 2)
	{
		i = -1;
		min = stack_a[i + 1];
		while (++i < *size_a)
		{
			if (stack_a[i] <= min)
			{
				min = stack_a[i];
				cmpt = i;
			}
		}
		position(cmpt, size_a, stack_a);
		pb(stack_a, stack_b, size_a, size_b);
	}
	three_numbers(stack_a, size_a);
	pa(stack_a, stack_b, size_a, size_b);
	pa(stack_a, stack_b, size_a, size_b);
}
