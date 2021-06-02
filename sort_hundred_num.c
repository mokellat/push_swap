/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred_num.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 11:50:22 by mokellat          #+#    #+#             */
/*   Updated: 2021/06/01 19:47:21 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    chunk(int *stack_a, int *size_a, int *stack_b, int *size_b, int minimum, int max)
{
    int i;
    int min;
    int cmpt;
    int index;
    int j;

    index = -1;
    while(++index < 100)
    {
        i = 0;
        min = stack_a[i];
        while(i < *size_a)
        {
            if(stack_a[i] >= minimum && stack_a[i] < max)
            {
                //min = stack_a[i];
                if(stack_a[i] <= min)
                {
                    min = stack_a[i];
                    cmpt = i;
                }
            }
            i++;
        }
        if(cmpt <= *size_a / 2 && min < max)
        {
            j = 0;
            while(j < cmpt)
            {
                ra(stack_a, *size_a);
                j++;
            }
            pb(stack_a, stack_b, size_a, size_b);
        }
        else if(cmpt > *size_a / 2 && min < max)
        {
            j = 0;
            while(j < *size_a - cmpt)
            {
                rra(stack_a, *size_a);
                j++;
            }
            pb(stack_a, stack_b, size_a, size_b);
        }
    }
}

void    hundred_num(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
    int i;

    i = 0;
    chunk(stack_a, size_a, stack_b, size_b, 0, 20);
    chunk(stack_a, size_a, stack_b, size_b, 20, 40);
    chunk(stack_a, size_a, stack_b, size_b, 40, 60);
    chunk(stack_a, size_a, stack_b, size_b, 60, 80);
    chunk(stack_a, size_a, stack_b, size_b, 80, 100);
    while(i < *size_b)
        pa(stack_a, stack_b, size_a, size_b);
}
