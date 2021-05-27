/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:33:49 by mokellat          #+#    #+#             */
/*   Updated: 2019/10/31 16:31:44 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ptr;
	unsigned int	i;
	unsigned int	j;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	j = 0;
	ptr = (char *)malloc((i + 1) * sizeof(char));
	if (ptr == NULL || f == NULL)
		return (NULL);
	while (j < i)
	{
		ptr[j] = f(j, s[j]);
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}
