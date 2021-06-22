/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 06:30:08 by mokellat          #+#    #+#             */
/*   Updated: 2021/06/22 11:16:42 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *s)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
	}
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	exec_fun_check(int size, int *stack_a, int size1, int *stack_b)
{
	if(!is_sorted(stack_a, &size))
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
	stack_a = malloc(sizeof(int) * size);
	stack_b = malloc(sizeof(int) * size);
	while (i < argc - 1)
	{
		stack_a[i] = ft_atoi(argv[i + 1]);
		if(ft_isdigit(stack_a[i] + '0'))
		{
			ft_putstr("ERROR!");
			free(stack_a);
			free(stack_b);
			exit(EXIT_FAILURE);
		}
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
	}
	if(is_sorted(stack_a, &size))
		ft_putstr("OK!");
	else
		ft_putstr("KO!");

}
