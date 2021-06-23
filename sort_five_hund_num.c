/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_hund_num.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 21:04:19 by mokellat          #+#    #+#             */
/*   Updated: 2021/06/23 19:46:20 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_transform_fhun(int *stack_a, int *size_a)
{
	int	min;
	int	index_i[2];
	int	cmpt;
	int	*temp;
	
	temp = (int *)malloc(*size_a * sizeof(int));
	index_i[1] = -1;
	while (++index_i[1] < 500)
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
	index_i[0] = -1;
	while (++index_i[0] < 500)
		stack_a[index_i[0]] = temp[index_i[0]];
	free(temp);
}

void	chunk_fhun(int *stack_a, int *size_a, int *stack_b, int *size_b)
{
	int	i;
	int	max;
	int	cmpt;
	int	index;

	index = 501;
	while (--index > 0)
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

void	chunk1_fhun(t_stack stack_a, t_stack stack_b, int minimum, int max)
{
	int	k;

	k = -1;
	while (++k < 500)
		condition_chunk1(stack_a, stack_b, minimum, max);
}

void	five_hun_num(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int	loop;
	int	plus;

	stack_transform_fhun(stack_a, size_a);
	loop = *size_a;
	plus = 40;
	while (loop > 0)
	{
		chunk1_fhun((t_stack){stack_a, size_a}, (t_stack){stack_b, size_b},
			loop - plus, loop);
		loop -= plus;
	}
	chunk_fhun(stack_a, size_a, stack_b, size_b);
}
