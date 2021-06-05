/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred_num.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 11:50:22 by mokellat          #+#    #+#             */
/*   Updated: 2021/06/05 15:31:40 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     min_search(int *stack_a, int *size_a)
{
    int i;
    int min;

    i = 0;
    min = stack_a[i];
    while(i < *size_a)
    {
        if(stack_a[i] <= min)
            min = stack_a[i];
        i++;
    }
    return (min);
}

int     max_search(int *stack_a, int *size_a)
{
    int i;
    int max;

    i = 0;
    max = stack_a[i];
    while(i < *size_a)
    {
        if(stack_a[i] >= max)
            max = stack_a[i];
        i++;
    }
    return (max);
}

void    chunk(int *stack_a, int *size_a, int *stack_b, int *size_b)
{
    int i;
    int maximum;
    int minimum;
    int max;
    int cmpt;
    int index;
    int j;

    i = 0;
    index = -1;
    minimum = min_search(stack_a, size_a);
    maximum = max_search(stack_a, size_a);
    while(++index < 100)
    {
        i = 0;
        max = stack_b[i];
        while(i < *size_b)
        {
            if(stack_b[i] >= 0 && stack_b[i] < 100)
            {
                if(stack_b[i] >= max)
                {
                    max = stack_b[i];
                    cmpt = i;
                }
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
           // printf("this is our number %d \n", stack_a[i]);
           // printf("this is our index %d \n", i);
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
    chunk1(stack_a, size_a, stack_b, size_b, 0, 20);
    chunk1(stack_a, size_a, stack_b, size_b, 20, 40);
    chunk1(stack_a, size_a, stack_b, size_b, 40, 60);
    chunk1(stack_a, size_a, stack_b, size_b, 60, 80);
    chunk1(stack_a, size_a, stack_b, size_b, 80, 100);
    chunk(stack_a, size_a, stack_b, size_b);
}
