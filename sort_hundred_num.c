/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred_num.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 11:50:22 by mokellat          #+#    #+#             */
/*   Updated: 2021/06/07 19:52:29 by mokellat         ###   ########.fr       */
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
        while(i < *size_a)
        {
            if(stack_a[i] <= min)
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
    }
}

void    chunk1(int *stack_a, int *size_a, int *stack_b, int *size_b, int minimum, int max)
{
    int i;
    int j;

    i = 0;
    while (*size_a > 0)
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
                    break ;
                }
            }
            else
                i++;
        }
    }
}

void    hundred_num(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
    int min;
    int max;
    int loop;

    min = min_search(stack_a, size_a);
    max = max_search(stack_a, size_a);
    loop = max;
    while(loop > min)
    {
        chunk1(stack_a, size_a, stack_b, size_b, loop - 20, loop);
        loop -= 20;
    }
    chunk(stack_a, size_a, stack_b, size_b);
}
