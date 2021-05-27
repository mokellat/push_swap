/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:06:17 by mokellat          #+#    #+#             */
/*   Updated: 2021/05/27 17:38:09 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     main()
{
    int ptr[] = {2, 5, 1, 4, 3};
    int ptr1[] = {};
    int size;
    int size1;
    
    size = sizeof ptr / sizeof *ptr;
    size1 = sizeof ptr1 / sizeof *ptr1;
    if(size > 1 )
    {
        if(size == 3)
            three_numbers(ptr, &size);
        if(size == 5)
            sort_five_num(ptr, ptr1, size, size1);
    }
    for(int i = 0; i < size; i++)
        printf("%d\n", ptr[i]);
    return 0;
}