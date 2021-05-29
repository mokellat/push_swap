/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:06:17 by mokellat          #+#    #+#             */
/*   Updated: 2021/05/28 11:35:53 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     main(int argc, char **argv)
{
    int *stack_a;
    int *stack_b;
    int size;
    int size1;
    int i;
    
    i = 0;
    size = argc - 1;
    size1 = 0;
    stack_a = malloc(sizeof(int) * size);
    stack_b = malloc(sizeof(int) * size);
    while(i < argc - 1)
    {
        stack_a[i] = ft_atoi(argv[i + 1]);
        i++;
    }
    if(size == 3)
        three_numbers(stack_a, &size);
    if(size == 5)
        sort_five_num(stack_a, stack_b, size, size1);
    return 0;
}