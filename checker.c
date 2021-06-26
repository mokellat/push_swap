/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 06:30:08 by mokellat          #+#    #+#             */
/*   Updated: 2021/06/24 18:30:19 by mokellat         ###   ########.fr       */
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

static void	fill_stack(int *stack, char **argv, int size)
{
	int	i;

	if (!is_int(argv, size + 1) || !double_arg(argv, size + 1))
	{
		ft_putstr("Error\n");
		free(stack);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < size)
	{
		stack[i] = ft_atoi(argv[i + 1]);
		i++;
	}
}

int main(int argc, char **argv)
{
	int		*stack_a;
	int		*stack_b;
	int		size;
	int		size1;
	//int		i;
	char	*line;

	size = argc - 1;
	size1 = 0;
	if (size < 1)
		return (0);
	stack_a = malloc(sizeof(int) * size);
	fill_stack(stack_a, argv, size);
	stack_b = malloc(sizeof(int) * size1);
	while(get_next_line(&line) > 0)
	{
		if(!ft_strcmp(line, "pa"))
			pa(stack_a, stack_b, &size, &size1);
		else if(!ft_strcmp(line, "pb"))
			pb(stack_a, stack_b, &size, &size1);
		else if(!ft_strcmp(line, "ra"))
			ra(stack_a, size);
		else if(!ft_strcmp(line, "rb"))
			rb(stack_b, size1);
		else if(!ft_strcmp(line, "rr"))
			rr(stack_a, stack_b, size);
		else if(!ft_strcmp(line, "rra"))
			rra(stack_a, size);
		else if(!ft_strcmp(line, "rrb"))
			rrb(stack_b, size1);
		else if(!ft_strcmp(line, "rrr"))
			rrr(stack_a, stack_b, size, size1);
		else if(!ft_strcmp(line, "sa"))
			sa(stack_a);
		else if(!ft_strcmp(line, "sb"))
			sb(stack_b);
		else if(!ft_strcmp(line, "ss"))
			ss(stack_a, stack_b);
		else
		{
			ft_putstr("Error\n");
			free_pointers(EXIT_FAILURE, line, stack_a, stack_b);
		}
	}
	if (is_sorted(stack_a, &size))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free_pointers(EXIT_SUCCESS, line, stack_a, stack_b);
}