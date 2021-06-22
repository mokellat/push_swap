/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:47:16 by mokellat          #+#    #+#             */
/*   Updated: 2021/06/22 09:15:06 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sa(int *stack_a)
{
	int	i;
	int	temp;

	i = 0;
	temp = stack_a[i];
	stack_a[i] = stack_a[i + 1];
	stack_a[i + 1] = temp;
	write(1, "sa\n", 3);
	return (stack_a);
}
