/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:05:50 by mokellat          #+#    #+#             */
/*   Updated: 2021/06/22 21:29:43 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

typedef struct s_stack
{
	int	*stack;
	int	*size;
}	t_stack;

int		*sa(int *stack_a);
int		*sb(int *stack_b);
void	ss(int *stack_a, int *stack_b);
int		*ra(int *stack_a, int size);
int		*rb(int *stack_b, int size);
void	rr(int *stack_a, int *stack_b, int size);
void	pa(int *stack_a, int *stack_b, int *size_a, int *size_b);
void	pb(int *stack_a, int *stack_b, int *size_a, int *size_b);
int		*rra(int *stack_a, int size);
int		*rrb(int *stack_a, int size);
void	rrr(int *stack_a, int *stack_b, int size_a, int size_b);
void	three_numbers(int *stack_a, int *size_a);
void	sort_five_num(int *stack_a, int *stack_b, int *size_a, int *size_b);
void	hundred_num(int *stack_a, int *stack_b, int *size_a, int *size_b);
void	five_hun_num(int *stack_a, int *stack_b, int *size_a, int *size_b);
void	other_nums(int *stack_a, int *stack_b, int *size_a, int *size_b);
void	condition_chunk(int cmpt, t_stack stack__a, t_stack stack__b);
void	condition_chunk1(t_stack stack_a, t_stack stack_b, int minimum,
			int max);
int		ft_atoi(const char *str);
int		is_sorted(int *stack_a, int *size_a);
int		get_next_line(char **line);
void	checker(void);
int		ft_strcmp(char *s1, char *s2);
int		ft_isdigit(int c);
void	ft_putstr(char *s);
size_t	ft_strlen(const char *str);

#endif
