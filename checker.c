/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 06:30:08 by mokellat          #+#    #+#             */
/*   Updated: 2021/06/23 12:47:33 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_pointers(int status, char *line, int *stack_a, int *stack_b, char *message)
{
	ft_putstr(message);
	free(line);
	free(stack_a);
	free(stack_b);
	exit(status);	
}

int main(int argc, char **argv)
{
	int		*stack_a;
	int		*stack_b;
	int		size;
	int		size1;
	int		i;
	char	*line;

	i = 0;
	size = argc - 1;
	size1 = 0;
	if (size < 1)
		return (0);
	if(!is_int(argv, argc) || !double_arg(argv, argc))
	{
		ft_putstr("ERROR\n");
		exit(EXIT_FAILURE);
	}
	stack_a = malloc(sizeof(int) * size);
	stack_b = malloc(sizeof(int) * size);
	while (i < argc - 1)
	{
		stack_a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
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
			free_pointers(EXIT_FAILURE, line, stack_a, stack_b, "ERROR\n");
	}
	if(is_sorted(stack_a, &size))
		free_pointers(EXIT_SUCCESS, line, stack_a, stack_b, "OK\n");
	else
		free_pointers(EXIT_SUCCESS, line, stack_a, stack_b, "KO\n");
}