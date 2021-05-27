/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 19:21:47 by mokellat          #+#    #+#             */
/*   Updated: 2021/05/27 17:18:29 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_five_num(int *stack_a, int *stack_b, int size_a, int size_b)
{
    int temp;

    temp = 0;
    pb(stack_a, stack_b, &size_a, &size_b);
    pb(stack_a, stack_b, &size_a, &size_b);
    three_numbers(stack_a, &size_a);
    if(stack_b[0] < stack_b[1])
    {
        temp = stack_b[0];
        stack_b[0] = stack_b[1];
        stack_b[1] = temp;
    }
    pa(stack_a, stack_b, &size_a, &size_b);
    if(stack_a[0] > stack_a[1])
        ra(stack_a, size_a);
    pa(stack_a, stack_b, &size_a, &size_b);
    if(stack_a[0] > stack_a[1])
        ra(stack_a, size_a);
}