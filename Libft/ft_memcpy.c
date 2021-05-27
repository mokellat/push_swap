/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokellat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 23:20:46 by mokellat          #+#    #+#             */
/*   Updated: 2019/11/06 23:23:37 by mokellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if ((!dst && !src) || dst == src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(char *)dst++ = *(char *)src++;
		i++;
	}
	return (dst - i);
}
