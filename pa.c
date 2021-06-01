/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:39:28 by mokellat          #+#    #+#             */
/*   Updated: 2021/05/31 15:40:10 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    pa(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
    int temp;
    int i;

    i = 0;
    temp = stack_b[0];
    i = 0;
    while(i < *size_b - 1)
    { 
        stack_b[i] = stack_b[i + 1];
        i++;
    }
    (*size_b)--;
    (*size_a)++;
    i = *(size_a);
    while(i >= 2)
    {
        stack_a[i - 1] = stack_a[i - 2];
        i--;
    }
    stack_a[0] = temp;
    write(1, "pa\n", 3);
}
