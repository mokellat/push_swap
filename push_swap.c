/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:06:17 by mokellat          #+#    #+#             */
/*   Updated: 2021/06/23 18:27:41 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_fun(int size, int *stack_a, int size1, int *stack_b)
{
	if (!is_sorted(stack_a, &size))
	{
		if (size == 3)
			three_numbers(stack_a, &size);
		else if (size == 5)
			sort_five_num(stack_a, stack_b, &size, &size1);
		else if (size == 100)
			hundred_num(stack_a, stack_b, &size, &size1);
		else if (size == 500)
			five_hun_num(stack_a, stack_b, &size, &size1);
		else
			other_nums(stack_a, stack_b, &size, &size1);
	}
}

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;
	int	size;
	int	size1;
	int	i;

	i = 0;
	size = argc - 1;
	size1 = 0;
	if ((!is_int(argv, argc) || !double_arg(argv, argc)))
	{
		ft_putstr("Error\n");
		exit(EXIT_FAILURE);
	}
	stack_a = malloc(sizeof(int) * size);
	stack_b = malloc(sizeof(int) * size);
	while (i < argc - 1)
	{
		stack_a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	exec_fun(size, stack_a, size1, stack_b);
	free(stack_a);
	free(stack_b);
}
