/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 19:21:47 by mokellat          #+#    #+#             */
/*   Updated: 2021/05/27 19:15:57 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_five_num(int *stack_a, int *stack_b, int size_a, int size_b)
{
    int temp;
    int i;
    int j;
    int compt;
    int max;

    temp = 0;
    compt = 0;
    pb(stack_a, stack_b, &size_a, &size_b);
    pb(stack_a, stack_b, &size_a, &size_b);
    three_numbers(stack_a, &size_a);
    max = stack_a[2];
    if(stack_b[0] < stack_b[1])                    
    {
        temp = stack_b[0];
        stack_b[0] = stack_b[1];
        stack_b[1] = temp;
    }
    while(compt < 2)
    {
        pa(stack_a, stack_b, &size_a, &size_b);
        i = 0;
        if(stack_a[0] > max)
        {
            max = stack_a[0];
            ra(stack_a, size_a);
        }
        else if(stack_a[i] > stack_a[i + 1] && stack_a[i] < stack_a[i + 2])
            sa(stack_a);
        else if(stack_a[i] > stack_a[i + 1] && stack_a[i] > stack_a[i + 2])
        {
            temp = stack_a[i];
            while(i < 3 + compt + 1)
            {
                if(temp < stack_a[i])
                {
                    
                }
                i++;
            }
        }
    }          
}