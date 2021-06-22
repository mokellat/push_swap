/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 06:30:08 by mokellat          #+#    #+#             */
/*   Updated: 2021/06/22 21:41:52 by mokellat         ###   ########.fr       */
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

int	check_arg(char **argv, int size)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while(i < size)
	{
		j = 0;
		while(j < (int)ft_strlen(argv[i]))
		{
			if(!ft_isdigit(argv[i][j]) && argv[i][j] != ' ')
			{
				return (0);
			}
			j++;	
		}
		i++;
	}
	return (1);
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
	if(!check_arg(argv, argc))
		{
			ft_putstr("ERROR!");
			exit(EXIT_FAILURE);
		}
	stack_a = malloc(sizeof(int) * size);
	stack_b = malloc(sizeof(int) * size);
	while (i < argc - 1)
	{
		stack_a[i] = ft_atoi(argv[i + 1]);
		printf("this is the stack %d \n", stack_a[i]);
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
