/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:48:43 by ebayat            #+#    #+#             */
/*   Updated: 2024/02/09 17:41:39 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*byteptr;

	byteptr = (const unsigned char *)s;
	while (n--)
	{
		if (*byteptr == (unsigned char)c)
			return ((void *)byteptr);
		byteptr++;
	}
	return (NULL);
}
