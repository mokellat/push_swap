/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_hund_num.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 21:04:19 by mokellat          #+#    #+#             */
/*   Updated: 2021/06/10 21:16:43 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void     stack_transform_fhun(int *stack_a, int *size_a)
{
    int     i;
    int     min;
    int     index;
    int     cmpt;
    int     *temp;

    temp = (int *)malloc(*size_a * sizeof(int));
    index = 0;
    while(index < 500)
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
    while (i < 500)
    {
        stack_a[i] = temp[i];
        i++;
    }
}

void    chunk_fhund(int *stack_a, int *size_a, int *stack_b, int *size_b)
{
    int i;
    int max;
    int cmpt;
    int j;
    int index;

    i = 0;
    int k = 0;
    index = 501;
    while(--index > 0)
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

void    chunk1_fhund(int *stack_a, int *size_a, int *stack_b, int *size_b, int minimum, int max)
{   
    int i;
    int j;
    int k;

    i = 0;
    k = 0;
    while (k < 500)
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

void    five_hun_num(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
    int loop;
    int plus;

    
    stack_transform_fhun(stack_a, size_a);
    loop = 0;
    plus = 50;
    while(loop < 500)
    {
        chunk1_fhund(stack_a, size_a, stack_b, size_b, loop, loop + 100);
        loop += plus;
    }
    chunk_fhund(stack_a, size_a, stack_b, size_b);
}