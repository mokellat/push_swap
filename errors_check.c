/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 10:19:04 by mokellat          #+#    #+#             */
/*   Updated: 2021/06/23 13:38:23 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	double_arg(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_int(char **argv, int size)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while (i < size)
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		if (ft_strlen(argv[i]) > 10 + (size_t)j
			|| ft_atoi(argv[i]) > INT_MAX
			|| ft_atoi(argv[i]) < INT_MIN)
			return (0);
		while (j < (int)ft_strlen(argv[i]))
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' ')
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
