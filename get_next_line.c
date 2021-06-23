/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <mokellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 06:32:35 by mokellat          #+#    #+#             */
/*   Updated: 2021/06/23 19:10:53 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_strjoin(char *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i])
		i++;
	str = (char *)malloc(i + 2);
	if (!str)
		return (0);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(s);
	return (str);
}

int	get_next_line(char **line)
{
	char	*buffer;
	int		flag;

	buffer = (char *)malloc(2);
	*line = (char *)malloc(1);
	if (!line || !buffer)
		return (-1);
	*line[0] = '\0';
	flag = 1;
	while (flag)
	{
		flag = read(0, buffer, 1);
		if (buffer[0] == '\n')
			break ;
		*line = ft_strjoin(*line, buffer[0]);
	}
	free(buffer);
	return (flag);
}
