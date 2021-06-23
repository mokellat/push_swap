/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:51:59 by mokellat          #+#    #+#             */
/*   Updated: 2021/06/23 10:59:30 by mokellat         ###   ########.fr       */
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
	int	i_j[2];

	i_j[0] = -1;
	while (++i_j[0] < *stack_a.size)
	{
		if (stack_a.stack[i_j[0]] >= minimum && stack_a.stack[i_j[0]] < max)
		{
			if (i_j[0] < *stack_a.size / 2)
			{
				i_j[1] = -1;
				while (++i_j[1] < i_j[0])
					ra(stack_a.stack, *stack_a.size);
				pb(stack_a.stack, stack_b.stack, stack_a.size, stack_b.size);
				break ;
			}
			else
			{
				i_j[0] = -1;
				while (++i_j[1] < *stack_a.size - i_j[0])
					rra(stack_a.stack, *stack_a.size);
				pb(stack_a.stack, stack_b.stack, stack_a.size, stack_b.size);
				break ;
			}
		}
	}
}

long	ft_atoi(const char *str)
{
	long	neg;
	int	i;
	long	num;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * neg);
}

int	is_sorted(int *stack_a, int *size_a)
{
	int	i;

	i = 0;
	while(i < *size_a && i + 1 < *size_a)
	{
		if(stack_a[i] > stack_a[i + 1])
			return (0);
		else
			i++;
	}
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}