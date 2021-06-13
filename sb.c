/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:35:12 by mokellat          #+#    #+#             */
/*   Updated: 2021/06/13 16:52:33 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sb(int *stack_b)
{
	int	i;
	int	temp;

	i = 0;
	temp = stack_b[i];
	stack_b[i] = stack_b[i + 1];
	stack_b[i + 1] = temp;
	write(1, "sb\n", 3);
	return (stack_b);
}
