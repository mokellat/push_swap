/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:39:57 by mokellat          #+#    #+#             */
/*   Updated: 2021/06/13 16:50:19 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(int *stack_a, int *stack_b, int size_a, int size_b)
{
	rra(stack_a, size_a);
	rrb(stack_b, size_b);
	write(1, "rrr\n", 4);
}
