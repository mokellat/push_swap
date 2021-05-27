/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 01:18:01 by mokellat          #+#    #+#             */
/*   Updated: 2019/11/05 14:47:28 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static int	*str_cat(char *str, char c)
{
	int	*ptr;
	int	i;
	int	j;
	int	cpt;

	cpt = 0;
	i = 0;
	j = 0;
	ptr = (int *)malloc((str_count(str, c)) * sizeof(int));
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			cpt++;
			if (str[i + 1] == c || str[i + 1] == '\0')
			{
				ptr[j++] = cpt;
				cpt = 0;
			}
			i++;
		}
	}
	return (ptr);
}

char		**ft_split(char const *s, char c)
{
	char	**str;
	int		n;
	int		*ptr;
	char	*s1;

	if (!s)
		return (NULL);
	s1 = ft_strdup(s);
	n = str_count((char *)s, c);
	if (!(ptr = (int *)malloc(n * sizeof(int))))
		return (NULL);
	ptr = str_cat((char *)s, c);
	str = (char **)malloc(sizeof(char *) * (n + 1));
	if (!str)
		return (NULL);
	return (put_split(c, str, ptr, s1));
}
