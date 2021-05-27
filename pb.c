/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 13:24:41 by mokellat          #+#    #+#             */
/*   Updated: 2021/05/26 16:14:56 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    pb(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
    int temp;
    int i;

    i = 0;
    temp = stack_a[0];
    i = 0;
    while(i < *size_a - 1)
    {
        stack_a[i] = stack_a[i + 1];
        i++;
    }
    (*size_a)--;
    (*size_b)++;
    i = *(size_b);
    while(i >= 2)
    {
        stack_b[i - 1] = stack_b[i - 2];
        i--;
    }
    stack_b[0] = temp;
    write(1, "pb\n", 3);
}