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

void    chunk_1(int *stack_a, int size_a)
{
    int i;
    int min;
    int cmpt;

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
}

void    hundred_num(int *stack_a, int *stack_b, int size_a, int size_b)
{
    
}