/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred_num.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 11:50:22 by mokellat          #+#    #+#             */
/*   Updated: 2021/06/13 19:21:40 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	condition_chunk(int cmpt, int *stack_a, int *stack_b,
int *size_a, int *size_b)
{
	int	j;

	if (cmpt <= *size_b / 2)
	{
		j = -1;
		while (++j < cmpt)
			rb(stack_b, *size_b);
		pa(stack_a, stack_b, size_a, size_b);
	}
	else if (cmpt > *size_b / 2)
	{
		j = -1;
		while (++j < *size_b - cmpt)
			rrb(stack_b, *size_b);
		pa(stack_a, stack_b, size_a, size_b);
	}
}

void	stack_transform(int *stack_a, int *size_a)
{
	int	i;
	int	min;
	int	index;
	int	cmpt;
	int	*temp;

	temp = (int *)malloc(*size_a * sizeof(int));
	index = -1;
	while (++index < 100)
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
		temp[cmpt] = index + 1;
		stack_a[cmpt] = INT_MAX;
	}
	i = -1;
	while (++i < 100)
		stack_a[i] = temp[i];
}

void	chunk(int *stack_a, int *size_a, int *stack_b, int *size_b)
{
	int	i;
	int	max;
	int	cmpt;
	int	index;

	index = 101;
	while (--index > 0)
	{
		i = -1;
		max = stack_b[i + 1];
		while (++i < *size_b)
		{
			if(stack_b[i] >= max)
			{
				max = stack_b[i];
				cmpt = i;
			}
		}
		condition_chunk(cmpt, stack_a, stack_b, size_a, size_b);
	}
}

void	chunk1(int *stack_a, int *size_a, int *stack_b, int *size_b, int minimum, int max)
{
	int	i;
	int	j;
	int	k;

	k = -1;
	while (++k < 100)
	{
		i = -1;
		while (++i < *size_a)
		{
			if (stack_a[i] >= minimum && stack_a[i] < max)
			{
				if (i < *size_a / 2)
				{
					j = -1;
					while (++j < i)
						ra(stack_a, *size_a);
					pb(stack_a, stack_b, size_a, size_b);
					break ;
				}
				else
				{
					j = -1;
					while (++j < *size_a - i)
						rra(stack_a, *size_a);
					pb(stack_a, stack_b, size_a, size_b);
					break ;
				}
			}
		}
	}
}

void	hundred_num(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int	loop;
	int	plus;


	stack_transform(stack_a, size_a);
	loop = *size_a;
	plus = 20;
	while (loop > 0)
	{
		chunk1(stack_a, size_a, stack_b, size_b, loop - plus, loop);
		loop -= plus;
	}
	chunk(stack_a, size_a, stack_b, size_b);
}
