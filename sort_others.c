/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_others.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:43:48 by mokellat          #+#    #+#             */
/*   Updated: 2021/06/24 17:16:12 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_fun_others(int index, int *temp, int *stack_a, int size)
{
	index = -1;
	while (++index < size)
		stack_a[index] = temp[index];
	free(temp);
}

void	stack_transform_others(int *stack_a, int *size_a)
{
	int	min;
	int	index_i[2];
	int	cmpt;
	int	*temp;

	temp = (int *)malloc(*size_a * sizeof(int));
	index_i[1] = -1;
	while (++index_i[1] < *size_a)
	{
		index_i[0] = -1;
		min = stack_a[index_i[0] + 1];
		while (++index_i[0] < *size_a)
		{
			if (stack_a[index_i[0]] <= min)
			{
				min = stack_a[index_i[0]];
				cmpt = index_i[0];
			}
		}
		temp[cmpt] = index_i[1] + 1;
		stack_a[cmpt] = INT_MAX;
	}
	assign_fun_others(index_i[0], temp, stack_a, *size_a);
}

void	chunk_others(int *stack_a, int *size_a, int *stack_b, int *size_b)
{
	int	i;
	int	max;
	int	cmpt;

	while (*size_b > 0)
	{
		i = -1;
		max = stack_b[i + 1];
		while (++i < *size_b)
		{
			if (stack_b[i] >= max)
			{
				max = stack_b[i];
				cmpt = i;
			}
		}
		condition_chunk(cmpt, (t_stack){stack_a, size_a},
			(t_stack){stack_b, size_b});
	}
}

void	chunk1_others(t_stack stack_a, t_stack stack_b, int minimum, int max)
{
	int	k;
	int	index;

	k = -1;
	index = *stack_a.size;
	while (++k < index)
		condition_chunk1(stack_a, stack_b, minimum, max);
}

void	other_nums(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int	loop;
	int	plus;

	stack_transform_others(stack_a, size_a);
	loop = *size_a;
	plus = 20;
	while (loop > 0)
	{
		chunk1_others((t_stack){stack_a, size_a}, (t_stack){stack_b, size_b},
			loop - plus, loop);
		loop -= plus;
	}
	chunk_others(stack_a, size_a, stack_b, size_b);
}
