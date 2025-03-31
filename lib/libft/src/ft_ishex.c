/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elie <elie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:38:17 by elie              #+#    #+#             */
/*   Updated: 2024/03/14 18:56:01 by elie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

unsigned int	ft_ishex(int c)
{
	if (ft_strchr(HEX_BASE, ft_toupper(c)))
		return (c);
	return (0);
}
