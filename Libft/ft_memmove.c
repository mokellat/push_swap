/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 20:35:36 by mokellat          #+#    #+#             */
/*   Updated: 2019/11/06 23:08:19 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	fin_cpy(void *dst, const void *src, size_t len)
{
	while (len > 0)
	{
		((char *)dst)[len - 1] = ((char *)src)[len - 1];
		len--;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;

	i = 0;
	if ((!dst && !src) || dst == src)
		return (NULL);
	if (dst < src)
	{
		while (i < len)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	else
		fin_cpy(dst, src, len);
	return (dst);
}
