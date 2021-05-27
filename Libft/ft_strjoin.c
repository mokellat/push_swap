/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:09:35 by mokellat          #+#    #+#             */
/*   Updated: 2019/11/03 11:40:00 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		cpt;
	char	*new;

	i = 0;
	cpt = 0;
	if (!s1 || !s2)
		return (NULL);
	new = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (s1[i])
	{
		new[cpt++] = s1[i++];
	}
	i = 0;
	while (s2[i])
	{
		new[cpt++] = s2[i++];
	}
	new[cpt] = '\0';
	return (new);
}
