/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:05:50 by mokellat          #+#    #+#             */
/*   Updated: 2021/05/27 17:09:57 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "./Libft/libft.h"

int     *sa(int *stack_a);
int     *sb(int *stack_b);
void    ss(int *stack_a, int *stack_b);
int     *ra(int *stack_a, int size);
int     *rb(int *stack_b, int size);
void    rr(int *stack_a, int *stack_b, int size);
void    pa(int *stack_a, int *stack_b, int *size_a, int *size_b);
void    pb(int *stack_a, int *stack_b, int *size_a, int *size_b);
int     *rra(int *stack_a, int size);
int     *rrb(int *stack_a, int size);
void    three_numbers(int *stack_a, int *size_a);
void    sort_five_num(int *stack_a, int *stack_b, int size_a, int size_b);

#endif