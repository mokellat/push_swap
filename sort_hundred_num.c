/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred_num.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 11:50:22 by mokellat          #+#    #+#             */
/*   Updated: 2021/05/28 12:19:21 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    chunk_1(int *stack_a, int size_a, int *stack_b, int size_b)
{
    int i;
    int min;
    int cmpt;
    int index;
    int j;

    j = 0;
    index = -1;
    while(++index < 100)
    {
        i = 0;
        while(i < 100)
        {
            if(stack_a[i] >= 0 || stack_a[i] < 20)
            {
                min = stack_a[i];
                if(stack_a[i] <= min)
                {
                    min = stack_a[i];
                    cmpt = i;
                }
            }
            i++;
        }
        if(cmpt <= 50)
        {
            while(j < cmpt)
                ra(stack_a, size_a);
            pb(stack_b, stack_b, &size_a, &size_b);
        }
        else
        {
            j = 0;
            while(j < 50 - cmpt)
                rra(stack_a, size_a);
            pb(stack_a, stack_b, &size_a, &size_b);
        }
    }
}

void    hundred_num(int *stack_a, int *stack_b, int size_a, int size_b)
{
    int i;

    i = 0;
    while(i < 100)
    {
        chunk_1(stack_a, size_a, stack_b, size_b);
        i++;
    }
}