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

int exec(t_stack stack_a, t_stack stack_b, char *line)
{
	if (!ft_strcmp(line, "pa"))
		pa(stack_a.stack, stack_b.stack, stack_a.size, stack_b.size);
	else if (!ft_strcmp(line, "pb"))
		pb(stack_a.stack, stack_b.stack, stack_a.size, stack_b.size);
	else if (!ft_strcmp(line, "ra"))
		ra(stack_a.stack, *stack_a.size);
	else if (!ft_strcmp(line, "rb"))
		rb(stack_b.stack, *stack_b.size);
	else if (!ft_strcmp(line, "rr"))
		rr(stack_a.stack, stack_b.stack, *stack_a.size);
	else if (!ft_strcmp(line, "rra"))
		rra(stack_a.stack, *stack_a.size);
	else if (!ft_strcmp(line, "rrb"))
		rrb(stack_b.stack, *stack_b.size);
	else if (!ft_strcmp(line, "rrr"))
		rrr(stack_a.stack, stack_b.stack, *stack_a.size, *stack_b.size);
	else if (!ft_strcmp(line, "sa"))
		sa(stack_a.stack);
	else if (!ft_strcmp(line, "sb"))
		sb(stack_b.stack);
	else if (!ft_strcmp(line, "ss"))
		ss(stack_a.stack, stack_b.stack);
	else
		return (0);
	return (1);
}

void	check_int_double(char **argv, int argc, int *stack_a)
{
	int	i;

	i = 0;
	if(!is_int(argv, argc) || !double_arg(argv, argc))
	{
		ft_putstr("ERROR\n");
		exit(EXIT_FAILURE);
	}
	while (i < argc - 1)
	{
		stack_a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
}

void	sort(int *stack_a, int *stack_b, int size, char *line)
{
	if (is_sorted(stack_a, &size))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free_pointers(EXIT_SUCCESS, line, stack_a, stack_b);
}

int main(int argc, char **argv)
{
	int		*stack_a;
	int		*stack_b;
	int		size[2];
	int		i;
	char	*line;

	i = 0;
	size[0] = argc - 1;
	size[1] = 0;
	if (size[0] < 1)
		return (0);
	stack_a = malloc(sizeof(int) * size[0]);
	check_int_double(argv, argc, stack_a);
	stack_b = malloc(sizeof(int) * size[1]);
	while(get_next_line(&line) > 0)
	{
		if (exec((t_stack){stack_a, &size[0]},
		(t_stack){stack_b, &size[1]}, line) == 0)
		{
			ft_putstr("Error\n");
			free_pointers(EXIT_FAILURE, line, stack_a, stack_b);
		}
		free(line);
	}
	sort(stack_a, stack_b, size[0], line);
}