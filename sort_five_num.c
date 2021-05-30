/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 19:21:47 by mokellat          #+#    #+#             */
/*   Updated: 2021/05/28 10:14:40 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_five_num(int *stack_a, int *stack_b, int size_a, int size_b)
{
    int num_switch;
    int i;
    int j;
    int compt;
    int min;

    i = 0;
    num_switch = 0;
    while(num_switch < 2)
    {
        min = stack_a[0];
        compt = 0;
        i = 0;
        j = 0;
        while(i < 5 - num_switch)
        {
            if(stack_a[i] <= min)
            {
                min = stack_a[i];
                compt = i;
            }
            i++;
        }
        if(compt == 0)
            pb(stack_a, stack_b, &size_a, &size_b);
        else if(compt == 1)
        {
            sa(stack_a);
            pb(stack_a, stack_b, &size_a, &size_b);
        }
        else if(compt >= 2)
        {
            while(j++ < compt)
                ra(stack_a, size_a);
            pb(stack_a, stack_b, &size_a, &size_b);
        }
        else if(compt > 2)
        {
            while(j < size_a - compt - 1)
                rra(stack_a, size_a);
            pb(stack_a, stack_b, &size_a, &size_b);
        }
        else
        {
            rra(stack_a, size_a);
            pb(stack_a, stack_b, &size_a, &size_b);
        }
        num_switch++;
    }
    three_numbers(stack_a, &size_a);
    if(stack_b[0] < stack_b[1])
        rrb(stack_b, size_b);
    pa(stack_a, stack_b, &size_a, &size_b);
    pa(stack_a, stack_b, &size_a, &size_b); 
}