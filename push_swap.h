/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:05:50 by mokellat          #+#    #+#             */
/*   Updated: 2021/05/31 15:21:00 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "./Libft/libft.h"

#define ARG100 = "17 9 93 80 99 2 5 51 84 4 57 48 14 29 55 35 74 21 94 60 68 63 1 92 23 82 12 67 69 98 52 19 83 97 78 39 75 100 25 24 8 7 41 11 86 44 36 72 18 73 16 64 47 90 65 87 77 59 61 45 30 53 54 66 76 28 37 95 70 91 27 6 50 43 81 3 46 13 31 89 88 96 38 62 33 10 15 79 20 42 40 85 26 34 71 49 32 22 58 56";
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
void    hundred_num(int *stack_a, int *stack_b, int size_a, int size_b);

#endif
