/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:11:01 by mokellat          #+#    #+#             */
/*   Updated: 2019/11/05 12:47:17 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*delete_c(char *str, char c)
{
	int		i;
	int		j;
	char	s;
	int		n;

	i = 0;
	n = ft_strlen(str);
	while (i < n)
	{
		if (str[i] == c)
		{
			j = i;
			while (j < n)
			{
				s = str[j + 1];
				str[j + 1] = str[j];
				str[j] = s;
				j++;
			}
			i--;
			n--;
		}
		i++;
	}
	return (str);
}

static int	str_count(char *str, char c)
{
	int	i;
	int	cpt;

	cpt = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			if (str[i + 1] == c || str[i + 1] == '\0')
				cpt++;
			i++;
		}
	}
	return (cpt);
}

static void	*fr_ee(char **split, int i)
{
	while (i >= 0)
		free(split[i--]);
	free(split);
	return (NULL);
}

char		**put_split(char c, char **str, int *ptr, char *s1)
{
	int		n;
	int		i;
	int		j;
	char	*p;
	int		cpt;

	cpt = 0;
	i = 0;
	n = str_count((char *)s1, c);
	if (!(p = (char *)malloc((ft_strlen(delete_c(((char *)s1), c))
						* sizeof(char)))))
		return (NULL);
	p = delete_c((char *)s1, c);
	while (i < n)
	{
		str[i] = (char *)malloc(sizeof(char) * (ptr[i] + 1));
		if (!str)
			return (fr_ee(str, i));
		j = 0;
		while (j < ptr[i])
			str[i][j++] = p[cpt++];
		str[i++][j] = '\0';
	}
	str[i] = NULL;
	return (str);
}
