/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred_num.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 11:50:22 by mokellat          #+#    #+#             */
/*   Updated: 2021/06/14 20:37:30 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	condition_chunk(int cmpt, t_stack stack__a,
t_stack stack__b)
{
	int	j;
	int	*size_a;
	int	*size_b;
	int	*stack_a;
	int	*stack_b;

	size_a = stack__a.size;
	size_b = stack__b.size;
	stack_b = stack__b.stack;
	stack_a = stack__a.stack;
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

void	condition_chunk1(t_stack stack_a, t_stack stack_b, int minimum, int max)
{
	int	i;
	int	j;

	i = -1;
	while (++i < *stack_a.size)
	{
		if (stack_a.stack[i] >= minimum && stack_a.stack[i] < max)
		{
			if (i < *stack_a.size / 2)
			{
				j = -1;
				while (++j < i)
					ra(stack_a.stack, *stack_a.size);
				pb(stack_a.stack, stack_b.stack, stack_a.size, stack_b.size);
				break ;
			}
			else
			{
				j = -1;
				while (++j < *stack_a.size - i)
					rra(stack_a.stack, *stack_a.size);
				pb(stack_a.stack, stack_b.stack, stack_a.size, stack_b.size);
				break ;
			}
		}
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

void	chunk1(t_stack stack_a, t_stack stack_b, int minimum, int max)
{
	int	k;

	k = -1;
	while (++k < 100)
	{
		condition_chunk1(stack_a, stack_b, minimum, max);
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
		chunk1((t_stack){stack_a, size_a}, (t_stack){stack_b, size_b},
			loop - plus, loop);
		loop -= plus;
	}
	chunk(stack_a, size_a, stack_b, size_b);
}
