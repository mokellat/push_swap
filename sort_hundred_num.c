/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred_num.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 11:50:22 by mokellat          #+#    #+#             */
/*   Updated: 2021/06/06 21:53:32 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    stack_transform(int *stack_a, int *size_a)
{
    int i;
    int min;
    int index;
    int cmpt;

    index = 0;
    while(index < 100)
    {
        i = 0;
        min = stack_a[i];
        while(i < 100)
        {
            if(stack_a[i] < min)
            {
                min = stack_a[i];
                cmpt = i;
            }
            i++;
        }
        printf("this is the min %d \n", min);
        stack_a[cmpt] = index;
        printf("this is the new value and the index %d %d \n", stack_a[cmpt], index);
        index++;
    }
}

void    chunk(int *stack_a, int *size_a, int *stack_b, int *size_b)
{
    int i;
    int max;
    int cmpt;
    int index;
    int j;

    i = 0;
    index = -1;
    while(++index < 100)
    {
        i = 0;
        max = stack_b[i];
        while(i < *size_b)
        {
            if(stack_b[i] >= max)
            {
                max = stack_b[i];
                cmpt = i;
            }
            i++;
        }
        if(cmpt <= *size_b / 2)
        {
            j = 0;
            while(j < cmpt)
            {
                rb(stack_b, *size_b);
                j++;
            }
            pa(stack_a, stack_b, size_a, size_b);
        }
        else if(cmpt > *size_b / 2)
        {
            j = 0;
            while(j < *size_b - cmpt)
            {
                rrb(stack_b, *size_b);
                j++;
            }
            pa(stack_a, stack_b, size_a, size_b);
        }
    }
}

void    chunk1(int *stack_a, int *size_a, int *stack_b, int *size_b, int minimum, int max)
{
    int i;
    int j;

    i = 0;
    while (i < *size_a + 2)
    {
        if (stack_a[i] >= minimum && stack_a[i] < max)
        {
            if (i < *size_a / 2)
            {
                j = 0;
                while (j < i)
                {
                    ra(stack_a, *size_a);
                    j++;
                }
                pb(stack_a, stack_b, size_a, size_b);
                i = 0;
            }
            else
            {
                j = 0;
                while (j < *size_a - i )
                {
                    rra(stack_a, *size_a);
                    j++;
                }
                pb(stack_a, stack_b, size_a, size_b);
                i = 0;
            }
        }
        i++;
    }
}

void hundred_num(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
    stack_transform(stack_a, size_a);
    // chunk1(stack_a, size_a, stack_b, size_b, 0, 20);
    // chunk1(stack_a, size_a, stack_b, size_b, 20, 40);
    // chunk1(stack_a, size_a, stack_b, size_b, 40, 60);
    // chunk1(stack_a, size_a, stack_b, size_b, 60, 80);
    // chunk1(stack_a, size_a, stack_b, size_b, 80, 100);
    // chunk(stack_a, size_a, stack_b, size_b);
}
