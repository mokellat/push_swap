/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 11:01:45 by mokellat          #+#    #+#             */
/*   Updated: 2019/10/31 16:48:40 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
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

void		put_tab(char *ptr, int n)
{
	int		j;
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ptr[0] = '-';
		j = 1;
		nbr = nbr * -1;
	}
	else
		j = 0;
	while (nbr > 0)
	{
		ptr[j] = (nbr % 10) + 48;
		nbr = nbr / 10;
		j++;
	}
}

void		inverser_tab_neg(char *ptr, int n)
{
	int		j;
	int		i;
	char	c;
	long	nbr;

	nbr = n;
	i = ft_intlen(nbr);
	if (nbr < 0)
	{
		j = 1;
		while (j < i / 2 + 1)
		{
			c = ptr[i - j];
			ptr[i - j] = ptr[j];
			ptr[j] = c;
			j++;
		}
	}
}

void		inverser_tab_pos(char *ptr, int n)
{
	int		j;
	int		i;
	char	c;
	long	nbr;

	nbr = n;
	i = ft_intlen(nbr);
	if (nbr > 0)
	{
		j = 0;
		while (j < i / 2)
		{
			c = ptr[i - j - 1];
			ptr[i - j - 1] = ptr[j];
			ptr[j] = c;
			j++;
		}
	}
}

char		*ft_itoa(int n)
{
	char	*ptr;
	int		i;
	int		j;
	long	nbr;

	nbr = n;
	j = 0;
	i = ft_intlen(nbr);
	ptr = (char *)malloc((i + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	if (nbr == 0)
		ptr[0] = '0';
	put_tab(ptr, nbr);
	inverser_tab_pos(ptr, nbr);
	inverser_tab_neg(ptr, nbr);
	ptr[i] = '\0';
	return (ptr);
}
