/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred_num.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 11:50:22 by mokellat          #+#    #+#             */
/*   Updated: 2021/06/09 16:54:32 by mokellat         ###   ########.fr       */
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

void     stack_transform(int *stack_a, int *size_a)
{
    int     i;
    int     min;
    int     index;
    int     cmpt;
    int     *temp;

    temp = (int *)malloc(*size_a * sizeof(int));
    index = 0;
    while(index < 100)
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
    while (i < 100)
    {
        stack_a[i] = temp[i];
        i++;
    }
}

void    chunk(int *stack_a, int *size_a, int *stack_b, int *size_b)
{
    int i;
    int max;
    int cmpt;
    int j;
    int index;

    i = 0;
    int k = 0;
    index = -1;
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

void    chunk1(int *stack_a, int *size_a, int *stack_b, int *size_b, int minimum, int max)
{
    int i;
    int j;

    i = 0;
    int k = 0;
    while (k < 100)
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
                while (j < *size_a - i)
                {
                    rra(stack_a, *size_a);
                    j++;
                }
                pb(stack_a, stack_b, size_a, size_b);
                i = 0;
            }
        }
        k++;
        i++;
    }
}

void    hundred_num(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
    int loop;

    
    stack_transform(stack_a, size_a);
    loop = 100;
    while(loop > 0)
    {
        chunk1(stack_a, size_a, stack_b, size_b, loop - 20, loop);
        loop -= 20;
    }
    chunk(stack_a, size_a, stack_b, size_b);
}