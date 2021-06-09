/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:06:17 by mokellat          #+#    #+#             */
/*   Updated: 2021/06/09 16:55:34 by mokellat         ###   ########.fr       */
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
    else if(size == 5)
      sort_five_num(stack_a, stack_b, size, size1);
    else if(size == 100)
      hundred_num(stack_a, stack_b, &size, &size1);
    // printf("beginning of printing \n");
    // for(i = 0; i < size; i++)
    //     printf("%d \n", stack_a[i]);
    // printf("this is the second array \n");
    // for(i = 0; i < size1; i++)
    //     printf("%d \n", stack_b[i]);
    return 0;
}