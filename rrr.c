/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:39:57 by mokellat          #+#    #+#             */
/*   Updated: 2021/05/26 16:16:12 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rrr(int *stack_a, int *stack_b, int size_a, int size_b)
{
    rra(stack_a, size_a);
    rrb(stack_b, size_b);
    write(1, "rrr\n", 4);
}