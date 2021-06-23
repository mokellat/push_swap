/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 13:33:33 by mokellat          #+#    #+#             */
/*   Updated: 2021/06/23 13:16:38 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(int *stack_a, int *stack_b, int size)
{
	ra(stack_a, size);
	rb(stack_b, size);
	if (DISPLAY)
		write(1, "rr\n", 3);
}
