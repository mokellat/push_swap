/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 00:31:05 by mokellat          #+#    #+#             */
/*   Updated: 2019/11/06 23:07:18 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)src == (unsigned char)c)
		{
			*(unsigned char *)dst = *(unsigned char *)src;
			return (dst + 1);
		}
		*(unsigned char *)dst++ = *(unsigned char *)src++;
		i++;
	}
	return (NULL);
}
