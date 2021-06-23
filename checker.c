/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 06:30:08 by mokellat          #+#    #+#             */
/*   Updated: 2021/06/23 19:37:59 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_pointers(int status, char *line, int *stack_a, int *stack_b)
{
	free(line);
	free(stack_a);
	free(stack_b);
	exit(status);
}

int	main(int argc, char **argv)
{
	int		*stack_a;
	int		*stack_b;
	int		size;
	int		i;
	char	*line;

	i = 0;
	size = argc - 1;
	if (size < 1)
		return (0);
	if (!is_int(argv, argc) || !double_arg(argv, argc))
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
	while (get_next_line(&line) > 0)
	{
		if (!ft_strcmp(line, "pa"))
			pa(stack_a, stack_b, &size, &size);
		else if (!ft_strcmp(line, "pb"))
			pb(stack_a, stack_b, &size, &size);
		else if (!ft_strcmp(line, "ra"))
			ra(stack_a, size);
		else if (!ft_strcmp(line, "rb"))
			rb(stack_b, size);
		else if (!ft_strcmp(line, "rr"))
			rr(stack_a, stack_b, size);
		else if (!ft_strcmp(line, "rra"))
			rra(stack_a, size);
		else if (!ft_strcmp(line, "rrb"))
			rrb(stack_b, size);
		else if (!ft_strcmp(line, "rrr"))
			rrr(stack_a, stack_b, size, size);
		else if (!ft_strcmp(line, "sa"))
			sa(stack_a);
		else if (!ft_strcmp(line, "sb"))
			sb(stack_b);
		else if (!ft_strcmp(line, "ss"))
			ss(stack_a, stack_b);
		else
		{
			ft_putstr("Error\n");
			free_pointers(EXIT_FAILURE, line, stack_a, stack_b);
		}
	}
	if (is_sorted(stack_a, &size))
	{
		ft_putstr("OK\n");
		free_pointers(EXIT_SUCCESS, line, stack_a, stack_b);
	}
	else
	{
		ft_putstr("KO\n");
		free_pointers(EXIT_SUCCESS, line, stack_a, stack_b);
	}
}
