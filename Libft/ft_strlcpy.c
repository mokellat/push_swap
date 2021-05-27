/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:50:51 by mokellat          #+#    #+#             */
/*   Updated: 2019/11/06 23:17:46 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	srclen;
	size_t	i;

	srclen = ft_strlen(src);
	i = 0;
	if (!src)
		return (0);
	if (!src[i])
	{
		dest[i] = src[i];
		return (srclen);
	}
	if (size == 0 && *src)
	{
		return (srclen);
	}
	while ((i < size - 1) && *src != '\0')
	{
		*dest++ = *src++;
		i++;
	}
	*dest = '\0';
	return (srclen);
}
