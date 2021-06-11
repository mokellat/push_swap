/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_others.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:43:48 by mokellat          #+#    #+#             */
/*   Updated: 2021/06/11 16:01:56 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    stack_transform_others(int *stack_a, int *size_a)
{
    int     i;
    int     min;
    int     index;
    int     cmpt;
    int     *temp;

    temp = (int *)malloc(*size_a * sizeof(int));
    index = 0;
    while(index < *size_a)
    {
        i = 0;
        min = stack_a[i];
        while(i < *size_a)
        {
            if(stack_a[i] <= min)
            {
                min = stack_a[i];
                cmpt = i;
            }
            i++;
        }
        temp[cmpt] = index + 1;
        stack_a[cmpt] = INT_MAX;
        index++;
    }
    i = 0;
    while (i < *size_a)
    {
        stack_a[i] = temp[i];
        i++;
    }
}

void    chunk_others(int *stack_a, int *size_a, int *stack_b, int *size_b)
{
    int i;
    int max;
    int cmpt;
    int j;

    i = 0;
    int k = 0;
    while(*size_b > 0)
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
        k++;
    }
}

void    chunk1_others(int *stack_a, int *size_a, int *stack_b, int *size_b, int minimum, int max)
{   
    int i;
    int j;
    int k;
    int index;

    i = 0;
    k = 0;
    index = *size_a;
    while (k < index)
    {
        i = 0;
        while(i < *size_a)
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
                    break ;
                }
                else
                {
                    j = 0;
                    while (j < *size_a - i)
                    {
                        rra(stack_a, *size_a);
                        j++;
                    }
                    pb(stack_a, stack_b, size_a, size_b);
                    break;
                }
            }
            i++;
        }
        k++;
    }
}

void    other_nums(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
    int loop;
    int plus;

    
    stack_transform_others(stack_a, size_a);
    loop = *size_a;
    plus = 20;
    while(loop > 0)
    {
        chunk1_others(stack_a, size_a, stack_b, size_b, loop - plus, loop);
        loop -= plus;
    }
    chunk_others(stack_a, size_a, stack_b, size_b);
}