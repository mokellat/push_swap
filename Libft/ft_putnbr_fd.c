/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:09:50 by mokellat          #+#    #+#             */
/*   Updated: 2019/10/31 16:45:54 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intlen(int n)
{
	int		i;
	long	nbr;

	nbr = n;
	if (nbr <= 0)
	{
		i = 1;
		nbr = nbr * -1;
		while (nbr > 0)
		{
			nbr = nbr / 10;
			i++;
		}
	}
	else
	{
		i = 0;
		while (nbr > 0)
		{
			nbr = nbr / 10;
			i++;
		}
	}
	return (i);
}

void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int n;

	n = nb;
	if (nb < 0)
	{
		ft_putchar('-', fd);
		n = -1 * nb;
	}
	if (n < 10)
	{
		ft_putchar(n + '0', fd);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}
